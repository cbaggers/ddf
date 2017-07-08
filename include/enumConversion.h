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

int ETypeToInt(FbxNodeAttribute::EType attrType);
