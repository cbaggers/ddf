#pragma once
#include <fbxsdk.h>

//------------------------------------------------------------
// Enums

int InheritTypeToInt(FbxTransform::EInheritType pInheritType);

int EFbxQuatInterpModeToInt(EFbxQuatInterpMode mode);

int EFbxRotationOrderToInt(EFbxRotationOrder order);

int EShadingModeToInt(FbxNode::EShadingMode mode);
