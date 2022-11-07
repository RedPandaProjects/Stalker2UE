#pragma once
#include "Core.h"
#include "Engine.h"
#include "Editor.h"
#include "Subsystems/ImportSubsystem.h"
#include "Interfaces/IPluginManager.h"
#include "Misc/FeedbackContext.h"
#include "Factories/Factory.h"
#include "UObject/UObjectGlobals.h"
#include "PackageTools.h"
#include "Modules/ModuleManager.h"
#include "MainFrame/Public/Interfaces/IMainFrameModule.h"
#include "Internationalization/Internationalization.h"
#include "StaticMeshAttributes.h"
#include "MeshDescription.h"
#include "AssetRegistry/AssetRegistryModule.h"
#include "Materials/Material.h"
#include "Materials/MaterialInstance.h"
#include "Materials/MaterialExpressionStaticSwitchParameter.h"
#include "Materials/MaterialExpressionTextureSampleParameter2D.h"
#include "Materials/MaterialExpressionTextureSampleParameterCube.h"
#include "Materials/MaterialExpressionScalarParameter.h"
#include "Materials/MaterialExpressionVectorParameter.h"
#include "Materials/MaterialInstanceConstant.h"
#include "Engine/SkeletalMesh.h"
#include "EditorStyleSet.h"
#include "HAL/PlatformProcess.h"
#include "IDetailsView.h"
#include "Modules/ModuleManager.h"
#include "PropertyEditorModule.h"
#include "Widgets/Input/SButton.h"
#include "Widgets/Layout/SBox.h"
#include "Widgets/Layout/SUniformGridPanel.h"
#include "Widgets/Text/SInlineEditableTextBlock.h"
#include "Engine/World.h"
#include "Engine/StaticMeshActor.h"
#include "Rendering/SkeletalMeshLODImporterData.h"
#include "MeshUtilities/Public/MeshUtilities.h"
#include "ImportUtils/SkeletalMeshImportUtils.h"
#include "Rendering/SkeletalMeshLODModel.h"
#include "Rendering/SkeletalMeshModel.h"
#include "Animation/Skeleton.h"
#include "Misc/CString.h"
#include "Animation/AnimSequence.h"
#include "Sound/SoundWave.h"
#include "Engine/PointLight.h"
#include "Engine/Classes/Components/PointLightComponent.h"
#include "Engine/DirectionalLight.h"
#include "Engine/Classes/Components/DirectionalLightComponent.h"
#include "Engine/SpotLight.h"
#include "Engine/Classes/Components/SpotLightComponent.h"
#include "Materials/MaterialExpressionCustom.h"
#include "Materials/MaterialExpressionAdd.h"
#include "Materials/MaterialExpressionSubtract.h"
#include "Materials/MaterialExpressionDivide.h"
#include "Materials/MaterialExpressionMultiply.h"
#include "Materials/MaterialExpressionConstant.h"
#include "Materials/MaterialExpressionConstant2Vector.h"
#include "Materials/MaterialExpressionConstant3Vector.h"
#include "Materials/MaterialExpressionConstant4Vector.h"
#include "Materials/MaterialExpressionTextureCoordinate.h"
#include "Materials/MaterialExpressionReflectionVectorWS.h"
#include "Materials/MaterialExpressionTransform.h"
#include "Materials/MaterialExpressionTransformPosition.h"
#include "Materials/MaterialExpressionPower.h"
#include "Materials/MaterialExpressionClamp.h"
#include "Materials/MaterialExpressionStep.h"
#include "Materials/MaterialExpressionSmoothStep.h"
#include "Materials/MaterialExpressionWorldPosition.h"
#include "Materials/MaterialExpressionTemporalSobol.h"
#include "Materials/MaterialExpressionFrac.h"
#include "Materials/MaterialExpressionTime.h"
#include "Materials/MaterialExpressionOneMinus.h"
#include "Materials/MaterialExpressionLightVector.h"
#include "Materials/MaterialExpressionLinearInterpolate.h"
#include "Materials/MaterialExpressionComponentMask.h"
#include "Materials/MaterialExpressionPixelDepth.h"
#include "Materials/MaterialExpressionSceneDepth.h"
#include "Engine/TextureCube.h"
#include "MaterialUtilities/Public/MaterialUtilities.h"
#include "RendererInterface.h"
THIRD_PARTY_INCLUDES_START
#include "XrECore/stdafx.h"
#include "XrECore/Editor/ImageManager.h"
#include "XrECore/Editor/EditMesh.h"
#include "XrECore/Editor/EditObject.h"
#include "XrECore/Editor/Library.h"
#include "RedImageTool/RedImage.hpp"
THIRD_PARTY_INCLUDES_END
#include "Scene/ESceneClassList.h"
#include "Scene/iniStreamImpl.h"
#include "Scene/Entitys/CustomObject.h"
#include "Scene/Tools/Base/ESceneCustomMTools.h"
#include "Scene/Tools/Base/ESceneCustomOTools.h"
#include "Scene/Scene.h"
DECLARE_LOG_CATEGORY_EXTERN(LogXRayImporter, Log, All);