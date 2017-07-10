#include "include/enumConversion.h"
#include "include/exporters.h"
#include "include/node.h"
#include "include/character.h"
#include "include/attribute.h"
#include "include/surfacematerial.h"

//------------------------------------------------------------
// Nodes

static int nodeID = -1;

FbxUInt64 VisitNode(Exporters* exporters, FbxNode* pNode)
{
    if (!pNode) return -1;
    if (pNode->GetUserDataPtr()!=NULL) return (FbxUInt64)pNode->GetUserDataPtr();

    int id = nodeID+=1;
    pNode->SetUserDataPtr((void*)id);

    //
    // Target
    FbxUInt64 target = -1;
    FbxNode* targetNode = pNode->GetTarget();
    if (targetNode!=NULL)
    {
        VisitNode(exporters, targetNode);
        target = (FbxUInt64)targetNode->GetUserDataPtr();
    }

    FbxUInt64 targetUp = -1;
    FbxNode* targetNodeUp = pNode->GetTargetUp();
    if (targetNodeUp!=NULL)
    {
        targetUp = VisitNode(exporters, targetNodeUp);
    }

    FbxVector4 postTargetRotation = pNode->GetPostTargetRotation();
    FbxVector4 targetUpVector = pNode->GetTargetUpVector();

    //
    // Attributes.
    int attrCount = pNode->GetNodeAttributeCount();
    for(int i = 0; i < attrCount; i++)
    {
        FbxNodeAttribute* attrObj = pNode->GetNodeAttributeByIndex(i);
        int attrType = NodeAttributeETypeToInt(attrObj->GetAttributeType());
        FbxUInt64 attr = VisitAttribute(exporters, attrObj);
    }

    FbxUInt64 defaultAttr = -1;
    FbxNodeAttribute* defaultAttrObj = pNode->GetNodeAttribute();
    if (defaultAttrObj!=NULL)
    {
        defaultAttr = (FbxUInt64)defaultAttrObj->GetUserDataPtr();
    }

    //
    // Transformation Propagation
    FbxTransform::EInheritType pInheritType;
    pNode->GetTransformationInheritType(pInheritType);
    int inheritID = InheritTypeToInt(pInheritType);

    //
    // Character Links
    int characterLinkCount = pNode->GetCharacterLinkCount();
    for(int i = 0; i < characterLinkCount; i++)
    {
        FbxCharacter* pCharacter = NULL;
        int pCharacterLinkType;
        int pNodeId;
        int pNodeSubId; // fbx internals, not of interest to us

        if (pNode->GetCharacterLink (i, &pCharacter, &pCharacterLinkType, &pNodeId, &pNodeSubId))
        {
            FbxUInt64 characterID = VisitCharacter(exporters, pCharacter);
            FbxCharacterLink::EType linkType = (FbxCharacterLink::EType)pCharacterLinkType;
            FbxEffector::ENodeId nodeID = (FbxEffector::ENodeId)pNodeId;
        }
    }

    //
    // Materials
    int materialCount = pNode->GetMaterialCount();
    for(int i = 0; i < materialCount; i++)
    {
        FbxSurfaceMaterial* materialObj = pNode->GetMaterial(i);
        FbxUInt64 material = VisitSurfaceMaterial(exporters, materialObj);
    }

    //
    // Properties
    FbxBool freeze = pNode->Freeze.Get();
    FbxBool lodBox = pNode->LODBox.Get();
    FbxBool negativePercentShapeSupport = pNode->NegativePercentShapeSupport.Get();
    FbxBool rotationActive = pNode->RotationActive.Get();
    FbxBool rotationMaxX = pNode->RotationMaxX.Get();
    FbxBool rotationMaxY = pNode->RotationMaxY.Get();
    FbxBool rotationMaxZ = pNode->RotationMaxZ.Get();
    FbxBool rotationMinX = pNode->RotationMinX.Get();
    FbxBool rotationMinY = pNode->RotationMinY.Get();
    FbxBool rotationMinZ = pNode->RotationMinZ.Get();
    FbxBool rotationSpaceForLimitOnly = pNode->RotationSpaceForLimitOnly.Get();
    FbxBool scalingActive = pNode->ScalingActive.Get();
    FbxBool scalingMaxX = pNode->ScalingMaxX.Get();
    FbxBool scalingMaxY = pNode->ScalingMaxY.Get();
    FbxBool scalingMaxZ = pNode->ScalingMaxZ.Get();
    FbxBool scalingMinX = pNode->ScalingMinX.Get();
    FbxBool scalingMinY = pNode->ScalingMinY.Get();
    FbxBool scalingMinZ = pNode->ScalingMinZ.Get();
    FbxBool show = pNode->Show.Get();
    FbxBool translationActive = pNode->TranslationActive.Get();
    FbxBool translationMaxX = pNode->TranslationMaxX.Get();
    FbxBool translationMaxY = pNode->TranslationMaxY.Get();
    FbxBool translationMaxZ = pNode->TranslationMaxZ.Get();
    FbxBool translationMinX = pNode->TranslationMinX.Get();
    FbxBool translationMinY = pNode->TranslationMinY.Get();
    FbxBool translationMinZ = pNode->TranslationMinZ.Get();
    FbxBool visibilityInheritance = pNode->VisibilityInheritance.Get();
    FbxDouble axisLen = pNode->AxisLen.Get();
    FbxDouble maxDampRangeX = pNode->MaxDampRangeX.Get();
    FbxDouble maxDampRangeY = pNode->MaxDampRangeY.Get();
    FbxDouble maxDampRangeZ = pNode->MaxDampRangeZ.Get();
    FbxDouble maxDampStrengthX = pNode->MaxDampStrengthX.Get();
    FbxDouble maxDampStrengthY = pNode->MaxDampStrengthY.Get();
    FbxDouble maxDampStrengthZ = pNode->MaxDampStrengthZ.Get();
    FbxDouble minDampRangeX = pNode->MinDampRangeX.Get();
    FbxDouble minDampRangeY = pNode->MinDampRangeY.Get();
    FbxDouble minDampRangeZ = pNode->MinDampRangeZ.Get();
    FbxDouble minDampStrengthX = pNode->MinDampStrengthX.Get();
    FbxDouble minDampStrengthY = pNode->MinDampStrengthY.Get();
    FbxDouble minDampStrengthZ = pNode->MinDampStrengthZ.Get();
    FbxDouble preferedAngleX = pNode->PreferedAngleX.Get();
    FbxDouble preferedAngleY = pNode->PreferedAngleY.Get();
    FbxDouble preferedAngleZ = pNode->PreferedAngleZ.Get();
    FbxDouble rotationStiffnessX = pNode->RotationStiffnessX.Get();
    FbxDouble rotationStiffnessY = pNode->RotationStiffnessY.Get();
    FbxDouble rotationStiffnessZ = pNode->RotationStiffnessZ.Get();
    FbxDouble visibility = pNode->Visibility.Get();
    FbxDouble3 geometricRotation = pNode->GeometricRotation.Get();
    FbxDouble3 geometricScaling = pNode->GeometricScaling.Get();
    FbxDouble3 geometricTranslation = pNode->GeometricTranslation.Get();
    FbxDouble3 lclRotation = pNode->LclRotation.Get();
    FbxDouble3 lclScaling = pNode->LclScaling.Get();
    FbxDouble3 lclTranslation = pNode->LclTranslation.Get();
    FbxDouble3 postRotation = pNode->PostRotation.Get();
    FbxDouble3 preRotation = pNode->PreRotation.Get();
    FbxDouble3 rotationMax = pNode->RotationMax.Get();
    FbxDouble3 rotationMin = pNode->RotationMin.Get();
    FbxDouble3 rotationOffset = pNode->RotationOffset.Get();
    FbxDouble3 rotationPivot = pNode->RotationPivot.Get();
    FbxDouble3 scalingMax = pNode->ScalingMax.Get();
    FbxDouble3 scalingMin = pNode->ScalingMin.Get();
    FbxDouble3 scalingOffset = pNode->ScalingOffset.Get();
    FbxDouble3 scalingPivot = pNode->ScalingPivot.Get();
    FbxDouble3 translationMax = pNode->TranslationMax.Get();
    FbxDouble3 translationMin = pNode->TranslationMin.Get();
    FbxInt defaultAttributeIndex = pNode->DefaultAttributeIndex.Get();
    int inherit = InheritTypeToInt(pNode->InheritType.Get());
    int quaternionInterpolate = EFbxQuatInterpModeToInt(pNode->QuaternionInterpolate.Get());
    int rotationOrder = EFbxRotationOrderToInt(pNode->RotationOrder.Get());
    // FbxReference lookAtProperty = pNode->LookAtProperty.Get();
    // FbxReference upVectorProperty = pNode->UpVectorProperty.Get();
    // bool visibility = pNode->GetVisibility(); think this is just the property

    //
    // Shading Mode
    int shadingMode = EShadingModeToInt(pNode->GetShadingMode());

    //
    // Pivot
    bool getRotationActive = pNode->GetRotationActive();
    FbxVector4 getRotationStiffness = pNode->GetRotationStiffness();
    FbxVector4 getMinDampRange = pNode->GetMinDampRange();
    FbxVector4 getMaxDampRange = pNode->GetMaxDampRange();
    FbxVector4 getMinDampStrength = pNode->GetMinDampStrength();
    FbxVector4 getMaxDampStrength = pNode->GetMaxDampStrength();
    FbxVector4 getPreferedAngle = pNode->GetPreferedAngle();
    //int quatInterpolation = EFbxQuatInterpModeToInt(pNode->GetQuaternionInterpolation(EPivotSet pPivotSet));
    // bool getUseRotationSpaceForLimitOnly = pNode->GetUseRotationSpaceForLimitOnly(EPivotSet pPivotSet);
    // FbxVector4 getGeometricTranslation = pNode->GetGeometricTranslation(EPivotSet pPivotSet);
    // FbxVector4 getGeometricRotation = pNode->GetGeometricRotation(EPivotSet pPivotSet);
    // FbxVector4 getGeometricScaling = pNode->GetGeometricScaling(EPivotSet pPivotSet);
    // const FbxVector4& pNode->GetRotationOffset(EPivotSet pPivotSet);
    // const FbxVector4& pNode->GetRotationPivot(EPivotSet pPivotSet);
    // const FbxVector4& pNode->GetPreRotation(EPivotSet pPivotSet);
    // const FbxVector4& pNode->GetPostRotation(EPivotSet pPivotSet);
    // const FbxVector4& pNode->GetScalingOffset(EPivotSet pPivotSet);
    // const FbxVector4& pNode->GetScalingPivot(EPivotSet pPivotSet)p;
    // void pNode->GetPivotState(EPivotSet pPivotSet, EPivotState& pPivotState);
    // void GetRotationOrder(EPivotSet pPivotSet, EFbxRotationOrder& pRotationOrder);

    //
    // Name
    const char* nodeName = pNode->GetName();

    // Visit the children.
    int childCount = pNode->GetChildCount();
    for(int j = 0; j < childCount; j++)
    {
        VisitNode(exporters, pNode->GetChild(j));
    }
    return id;
}
