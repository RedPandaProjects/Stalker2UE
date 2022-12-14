// Copyright(c) 2021 Vadim Slyusarev 

#pragma once
#include "optick.config.h"

#if USE_OPTICK

#include "optick_common.h"
#include "optick_memory.h"

//////////////////////////////////////////////////////////////////////////
// Platform-specific stuff
//////////////////////////////////////////////////////////////////////////
namespace Optick
{
        struct Trace;
        struct Module;
        struct Symbol;
        struct SymbolEngine;

        ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        // Platform API
        ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        struct Platform
        {
                // Platform Name
                static OPTICK_INLINE const char* GetName();
                // Thread ID (system thread id)
                static OPTICK_INLINE ThreadID GetThreadID();
                // Process ID
                static OPTICK_INLINE ProcessID GetProcessID();
                // CPU Frequency
                static OPTICK_INLINE int64 GetFrequency();
                // CPU Time (Ticks)
                static OPTICK_INLINE int64 GetTime();
                // System Tracer
                static OPTICK_INLINE Trace* CreateTrace();
                // Symbol Resolver
                static OPTICK_INLINE SymbolEngine* CreateSymbolEngine();
        };

        ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        // Tracing API
        ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        struct Trace
        {
                virtual void SetPassword(const char* /*pwd*/) {};
                virtual CaptureStatus::Type Start(Mode::Type mode, int frequency, const ThreadList& threads) = 0;
                virtual bool Stop() = 0;
                virtual ~Trace() {};
        };


        ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        // Symbol API
        ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

        ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        struct Module
        {
                string path;
                void* address;
                size_t size;
                Module(const char* p, void* a, size_t s) : path(p), address(a), size(s) {}
        };
        ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        struct Symbol
        {
                uint64 address;
                uint64 offset;
                wstring file;
                wstring function;
                uint32 line;
                Symbol()
                        : address(0)
                        , offset(0)
                        , line(0)
                {}
        };
        ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        struct SymbolEngine
        {
                // Get list of loaded modules
                virtual const vector<Module>& GetModules() = 0;

                // Get Symbol from address
                virtual const Symbol* GetSymbol(uint64 dwAddress) = 0;

                virtual ~SymbolEngine() {};
        };
}
//////////////////////////////////////////////////////////////////////////

#endif //USE_OPTICK
