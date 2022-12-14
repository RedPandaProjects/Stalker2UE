// Copyright(c) 2021 Vadim Slyusarev 

#pragma once
#include "optick.config.h"

#if USE_OPTICK

#include <atomic>
#include <mutex>

#include "optick_common.h"
#include "optick_memory.h"

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
namespace Optick
{
        const char* GetGPUQueueName(GPUQueueType queue);
        ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        class GPUProfiler
        {
        public:
                static const int MAX_FRAME_EVENTS = 1024;
                static const int NUM_FRAMES_DELAY = 4;
                static const int MAX_QUERIES_COUNT = (2 * MAX_FRAME_EVENTS) * NUM_FRAMES_DELAY;
        protected:

                enum State
                {
                        STATE_OFF,
                        STATE_STARTING,
                        STATE_RUNNING,
                        STATE_FINISHING,
                };

                struct ClockSynchronization
                {
                        int64_t frequencyCPU;
                        int64_t frequencyGPU;
                        int64_t timestampCPU;
                        int64_t timestampGPU;

                        int64_t GetCPUTimestamp(int64_t gpuTimestamp)
                        {
                                return timestampCPU + (gpuTimestamp - timestampGPU) * frequencyCPU / frequencyGPU;
                        }

                        ClockSynchronization() : frequencyCPU(0), frequencyGPU(0), timestampCPU(0), timestampGPU(0) {}
                };

                struct QueryFrame
                {
                        EventData* frameEvent;
                        uint32_t queryIndexStart;
                        uint32_t queryIndexCount;

                        QueryFrame()
                        {
                                Reset();
                        }

                        void Reset()
                        {
                                frameEvent = nullptr;
                                queryIndexStart = (uint32_t)-1;
                                queryIndexCount = 0;
                        }
                };

                struct Node
                {
                        array<QueryFrame, NUM_FRAMES_DELAY> queryGpuframes;
                        array<int64_t, MAX_QUERIES_COUNT> queryGpuTimestamps;
                        array<int64_t*, MAX_QUERIES_COUNT> queryCpuTimestamps;
                        std::atomic<uint32_t> queryIndex;

                        ClockSynchronization clock;

                        array<EventStorage*, GPU_QUEUE_COUNT> gpuEventStorage;

                        uint32_t QueryTimestamp(int64_t* outCpuTimestamp)
                        {
                                uint32_t index = queryIndex.fetch_add(1) % MAX_QUERIES_COUNT;
                                queryCpuTimestamps[index] = outCpuTimestamp;
                                return index;
                        }

                        string name;

                        void Reset();

                        Node() : queryIndex(0) { gpuEventStorage.fill(nullptr); }
                };

                std::recursive_mutex updateLock;
                volatile State currentState;

                vector<Node*> nodes;
                uint32_t currentNode;

                uint32_t frameNumber;

                void Reset();

                EventData& AddFrameEvent();
                EventData& AddVSyncEvent();
                TagData<uint32>& AddFrameTag();

        public:
                GPUProfiler();

                // Init
                virtual void InitNode(const char* nodeName, uint32_t nodeIndex);

                // Capture Controls 
                virtual void Start(uint32 mode);
                virtual void Stop(uint32 mode);
                virtual void Dump(uint32 mode);

                virtual string GetName() const;

                // Interface to implement
                virtual ClockSynchronization GetClockSynchronization(uint32_t nodeIndex) = 0;
                virtual void QueryTimestamp(void* context, int64_t* cpuTimestampOut) = 0;
                virtual void Flip(void* swapChain) = 0;

                virtual ~GPUProfiler();
        };
        ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
}

#endif //USE_OPTICK
