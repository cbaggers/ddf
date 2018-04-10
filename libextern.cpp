#include <stdio.h>
#include <fbxsdk.h>
#include <ctime>
#include <chrono>

struct Callbacks
{
    // when int == 0 is returned its means stop walking this thing
    int (*helloNode)(FbxNode*);
    int (*helloObject)(FbxObject*);
    int (*helloCharacter)(FbxCharacter*);
};

void VisitCharacter(Callbacks* callbacks, FbxCharacter* character)
{
    if (callbacks->helloCharacter(character) == 0) return;
    //callbacks->helloConstraint(character);
    callbacks->helloObject(character);

    // Input Object
    FbxCharacter::EInputType inputType = character->GetInputType();
    FbxObject* pInputObject = character->GetInputObject();
    if (inputType == FbxCharacter::eInputCharacter)
    {
        VisitCharacter(callbacks, (FbxCharacter*)pInputObject);
    }
}

void VisitNode(Callbacks* callbacks, FbxNode* node)
{
    if (callbacks->helloNode(node) == 0) return;
    callbacks->helloObject(node);

    //
    // Target
    FbxNode* targetNode = node->GetTarget();
    if (targetNode!=NULL)
    {
        VisitNode(callbacks, targetNode);
    }

    FbxNode* targetNodeUp = node->GetTargetUp();
    if (targetNodeUp!=NULL)
    {
        VisitNode(callbacks, targetNodeUp);
    }

    
    
    // //
    // // Attributes.
    // int attrCount = node->GetNodeAttributeCount();
    // for(int i = 0; i < attrCount; i++)
    // {
    //     FbxNodeAttribute* attrObj = node->GetNodeAttributeByIndex(i);
    //     // int attrType = NodeAttributeETypeToInt(attrObj->GetAttributeType());
    //     int attr = VisitAttribute(callbacks, attrObj);
    // }

    // //
    // // Character Links
    // int characterLinkCount = node->GetCharacterLinkCount();
    // for(int i = 0; i < characterLinkCount; i++)
    // {
    //     FbxCharacter* pCharacter = NULL;
    //     int pCharacterLinkType;
    //     int nodeId;
    //     int nodeSubId; // fbx internals, not of interest to us

    //     if (node->GetCharacterLink (i, &pCharacter, &pCharacterLinkType, &nodeId, &nodeSubId))
    //     {
    //         int characterID = VisitCharacter(callbacks, pCharacter);
    //         // FbxCharacterLink::EType linkType = (FbxCharacterLink::EType)pCharacterLinkType;
    //         // FbxEffector::ENodeId nodeID = (FbxEffector::ENodeId)nodeId;
    //     }
    // }

    // //
    // // Materials
    // int materialCount = node->GetMaterialCount();
    // for(int i = 0; i < materialCount; i++)
    // {
    //     FbxSurfaceMaterial* materialObj = node->GetMaterial(i);
    //     FbxUInt64 material = VisitSurfaceMaterial(callbacks, materialObj);
    // }

    // Visit the children.
    int childCount = node->GetChildCount();
    for(int j = 0; j < childCount; j++)
    {
        VisitNode(callbacks, node->GetChild(j));
    }
}

void VisitScene(Callbacks* callbacks, FbxScene* pScene)
{
    // // Global Settings
    // VisitGlobalSettings(&pScene->GetGlobalSettings());

    // // Nodes
    // // We dont visit the root node as it should have no attributes
    FbxNode* pRootNode = pScene->GetRootNode();
    for(int i = 0; i < pRootNode->GetChildCount(); i++)
    {
        VisitNode(callbacks, pRootNode->GetChild(i));
    }

    // Characters
    for(int i = 0; i < pScene->GetCharacterCount(); i++)
    {
        VisitCharacter(callbacks, pScene->GetCharacter(i));
    }
}

extern "C" void WalkFbx(Callbacks* callbacks)
{
    // Change the following filename to a suitable filename value.
    // Loader doesnt seem to like ~/
    const char* lFilename = "/home/baggers/Code/c++/dumb-dump-fbx/humanoid.fbx";

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

    // Walk, dumping dumbly
    VisitScene(callbacks, lScene);

    // Done
    lSdkManager->Destroy();
}
