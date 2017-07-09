#pragma once
#include <fbxsdk.h>

//------------------------------------------------------------
// Enums

int InheritTypeToInt(FbxTransform::EInheritType pInheritType);

int EFbxQuatInterpModeToInt(EFbxQuatInterpMode mode);

int EFbxRotationOrderToInt(EFbxRotationOrder order);

int EShadingModeToInt(FbxNode::EShadingMode mode);

int ERollExtractionModeToInt(FbxCharacter::ERollExtractionMode mode);

int EPostureModeToInt(FbxCharacter::EPostureMode mode);

int EOffAutoUserToInt(FbxCharacter::EOffAutoUser user);

int EAutoUserToInt(FbxCharacter::EAutoUser user);

int EFloorPivotToInt(FbxCharacter::EFloorPivot pivot);

int EHipsTranslationModeToInt(FbxCharacter::EHipsTranslationMode mode);

int EFootContactTypeToInt(FbxCharacter::EFootContactType mode);

int EHandContactTypeToInt(FbxCharacter::EHandContactType mode);

int EFingerContactModeToInt(FbxCharacter::EFingerContactMode mode);

int EContactBehaviourToInt(FbxCharacter::EContactBehaviour mode);

int NodeAttributeETypeToInt(FbxNodeAttribute::EType attrType);

int LayerElementETypeToInt(FbxLayerElement::EType attrType);

int LayerElementMappingModeToInt(FbxLayerElement::EMappingMode mode);

int LayerElementReferenceModeToInt(FbxLayerElement::EReferenceMode mode);

int CameraEProjectionTypeToInt(FbxCamera::EProjectionType mode);

int CameraEFormatToInt(FbxCamera::EFormat mode);

int CameraEAspectRatioModeToInt(FbxCamera::EAspectRatioMode mode);

int CameraEApertureFormatToInt(FbxCamera::EApertureFormat mode);

int CameraEApertureModeToInt(FbxCamera::EApertureMode mode);

int CameraEGateFitToInt(FbxCamera::EGateFit mode);

int CameraEFilmRollOrderToInt(FbxCamera::EFilmRollOrder mode);

int CameraEPlateDrawingModeToInt(FbxCamera::EPlateDrawingMode mode);

int CameraEFrontBackPlaneDistanceModeToInt(FbxCamera::EFrontBackPlaneDistanceMode mode);

int CameraEFrontBackPlaneDisplayModeToInt(FbxCamera::EFrontBackPlaneDisplayMode mode);

int CameraESafeAreaStyleToInt(FbxCamera::ESafeAreaStyle mode);

int CameraERenderOptionsUsageTimeToInt(FbxCamera::ERenderOptionsUsageTime mode);

int CameraEAntialiasingMethodToInt(FbxCamera::EAntialiasingMethod mode);

int CameraESamplingTypeToInt(FbxCamera::ESamplingType mode);

int CameraEFocusDistanceSourceToInt(FbxCamera::EFocusDistanceSource mode);
