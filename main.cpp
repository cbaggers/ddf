#include <stdio.h>
#include <fbxsdk.h>

#include "include/exporters.h"
#include "include/scene.h"

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

    // Walk, dumping dumbly
    VisitScene(exporters, lScene);

    // Destroy the SDK manager and all the other objects it was handling.
    lSdkManager->Destroy();
    return 0;
}
