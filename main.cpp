#include <stdio.h>
#include <fbxsdk.h>

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
// Attributes

void VisitAttribute(Exporters* exporters, FbxNodeAttribute* pAttribute)
{
    if(!pAttribute) return;
}


//------------------------------------------------------------
// Nodes

void VisitNode(Exporters* exporters, FbxNode* pNode)
{
    const char* nodeName = pNode->GetName();
    FbxDouble3 translation = pNode->LclTranslation.Get();
    FbxDouble3 rotation = pNode->LclRotation.Get();
    FbxDouble3 scaling = pNode->LclScaling.Get();

    // Visit the attributes.
    for(int i = 0; i < pNode->GetNodeAttributeCount(); i++)
        VisitAttribute(exporters, pNode->GetNodeAttributeByIndex(i));

    // Visit the children.
    for(int j = 0; j < pNode->GetChildCount(); j++)
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
