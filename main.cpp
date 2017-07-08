#include <stdio.h>
#include <fbxsdk.h>

//------------------------------------------------------------

static int nodeID = 0;

//------------------------------------------------------------
// Export logic

struct Buffer
{
    void* Data;
    FILE* file;
};

struct NodeExporter
{
    Buffer* buff;
};

struct Exporters
{
    NodeExporter* Node;
};

Buffer* MakeBuffer(const char* path)
{
    return new Buffer();
}

Exporters* InitExporters(const char* path)
{
    Exporters* r = new Exporters();
    NodeExporter* ne = new NodeExporter();
    ne->buff = MakeBuffer(path);
    return r;
}

//------------------------------------------------------------
// Enums

int InheritTypeToInt(FbxTransform::EInheritType pInheritType)
{
    switch (pInheritType)
    {
    case FbxTransform::eInheritRrSs: return 0;
    case FbxTransform::eInheritRSrs: return 1;
    case FbxTransform::eInheritRrs: return 2;
    }
    exit(2);
}

int EFbxQuatInterpModeToInt(EFbxQuatInterpMode mode)
{
    switch (mode)
    {
    case eQuatInterpOff: return 0;
    case eQuatInterpClassic: return 1;
    case eQuatInterpSlerp: return 2;
    case eQuatInterpCubic: return 3;
    case eQuatInterpTangentDependent: return 4;
    case eQuatInterpCount: return 5;
    }
    exit(3);
}

int EFbxRotationOrderToInt(EFbxRotationOrder order)
{
    switch (order)
    {
    case eEulerXYZ: return 0;
    case eEulerXZY: return 1;
    case eEulerYZX: return 2;
    case eEulerYXZ: return 3;
    case eEulerZXY: return 4;
    case eEulerZYX: return 5;
    case eSphericXYZ: return 6;
    }
    exit(4);
}

int EShadingModeToInt(FbxNode::EShadingMode mode)
{
    switch (mode)
    {
    case FbxNode::eHardShading: return 0;
    case FbxNode::eWireFrame: return 1;
    case FbxNode::eFlatShading: return 2;
    case FbxNode::eLightShading: return 3;
    case FbxNode::eTextureShading: return 4;
    case FbxNode::eFullShading: return 5;
    }
    exit(5);
}

//------------------------------------------------------------
// Attributes

void VisitAttribute(Exporters* exporters, FbxNodeAttribute* pAttribute)
{
    if(!pAttribute) return;
}

//------------------------------------------------------------
// Characters

void VisitCharacter(Exporters* exporters, FbxCharacter* pCharacter)
{
    if(!pCharacter) return;
}

//------------------------------------------------------------
// Surface Materials

void VisitSurfaceMaterial(Exporters* exporters, FbxSurfaceMaterial* pMaterial)
{
    if(!pMaterial) return;
}

//------------------------------------------------------------
// Nodes

void VisitNode(Exporters* exporters, FbxNode* pNode)
{
    if (!pNode) return;
    if (pNode->GetUserDataPtr() > 0) return;

    int id = nodeID+=1;
    pNode->SetUserDataPtr((void*)id);

    //
    // Target
    FbxUInt64 target = 0;
    FbxNode* targetNode = pNode->GetTarget();
    if (targetNode!=NULL)
    {
        VisitNode(exporters, targetNode);
        target = (FbxUInt64)targetNode->GetUserDataPtr();
    }

    FbxUInt64 targetUp = 0;
    FbxNode* targetNodeUp = pNode->GetTargetUp();
    if (targetNodeUp!=NULL)
    {
        VisitNode(exporters, targetNodeUp);
        targetUp = (FbxUInt64)targetNodeUp->GetUserDataPtr();
    }

    FbxVector4 postTargetRotation = pNode->GetPostTargetRotation();
    FbxVector4 targetUpVector = pNode->GetTargetUpVector();

    //
    // Attributes.
    int attrCount = pNode->GetNodeAttributeCount();
    for(int i = 0; i < attrCount; i++)
    {
        VisitAttribute(exporters, pNode->GetNodeAttributeByIndex(i));
        FbxUInt64 attrID = (FbxUInt64)targetNode->GetUserDataPtr();
    }

    FbxUInt64 defaultAttr = (FbxUInt64)pNode->GetNodeAttribute()->GetUserDataPtr();

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
        FbxCharacter** pCharacter = NULL;
        int* pCharacterLinkType = NULL;
        int* pNodeId = NULL;
        int* pNodeSubId = NULL; // fbx internals, not of interest to us

        if (pNode->GetCharacterLink (i, pCharacter, pCharacterLinkType, pNodeId, pNodeSubId))
        {
            VisitCharacter(exporters, *pCharacter);
            FbxUInt64 characterID = (FbxUInt64)((*pCharacter)->GetUserDataPtr());
            FbxCharacterLink::EType linkType = (FbxCharacterLink::EType)*pCharacterLinkType;
            FbxEffector::ENodeId nodeID = (FbxEffector::ENodeId)*pNodeId;
        }
    }

    //
    // Materials
    int materialCount = pNode->GetMaterialCount();
    for(int i = 0; i < materialCount; i++)
    {
        VisitSurfaceMaterial(exporters, pNode->GetMaterial(i));
        FbxUInt64 materialID = (FbxUInt64)targetNode->GetUserDataPtr();
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
    FbxReference lookAtProperty = pNode->LookAtProperty.Get();
    FbxReference upVectorProperty = pNode->UpVectorProperty.Get();
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
        VisitNode(exporters, pNode->GetChild(j));
}

//------------------------------------------------------------

int main(int argc, char** argv)
{

    // Change the following filename to a suitable filename value.
    // Loader doesnt seem to like ~/
    const char* lFilename = "/home/baggers/Code/c++/dumb-dump-fbx/humanoid.fbx";

    Exporters* exporters = InitExporters(lFilename);

    // Initialize the SDK manager. This object handles all our memory management.
    FbxManager* lSdkManager = FbxManager::Create();

    // Create the IO settings object.
    FbxIOSettings *ios = FbxIOSettings::Create(lSdkManager, IOSROOT);
    lSdkManager->SetIOSettings(ios);

    // Create an importer using the SDK manager.
    FbxImporter* lImporter = FbxImporter::Create(lSdkManager,"");

    // Use the first argument as the filename for the importer.
    if(!lImporter->Initialize(lFilename, -1, lSdkManager->GetIOSettings()))
    {
        printf("Call to FbxImporter::Initialize() failed.\n");
        printf("Error returned: %s\n\n", lImporter->GetStatus().GetErrorString());
        exit(-1);
    }

    // Create a new scene so that it can be populated by the imported file.
    FbxScene* lScene = FbxScene::Create(lSdkManager,"myScene");

    // Import the contents of the file into the scene.
    lImporter->Import(lScene);

    // The file is imported; so get rid of the importer.
    lImporter->Destroy();

    // Print the nodes of the scene and their attributes recursively.
    // Note that we are not printing the root node because it should
    // not contain any attributes.
    FbxNode* lRootNode = lScene->GetRootNode();
    if (lRootNode)
    {
        for(int i = 0; i < lRootNode->GetChildCount(); i++)
            VisitNode(exporters, lRootNode->GetChild(i));
    }
    // Destroy the SDK manager and all the other objects it was handling.
    lSdkManager->Destroy();
    return 0;
}
