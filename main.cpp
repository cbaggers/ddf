#include <stdio.h>
#include <fbxsdk.h>
#include <ctime>
#include <chrono>

int inner_foo()
{
    using namespace std::chrono;
    high_resolution_clock::time_point preInit = high_resolution_clock::now();

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

    high_resolution_clock::time_point postInit = high_resolution_clock::now();

    // Import the contents of the file into the scene.
    high_resolution_clock::time_point preImport = high_resolution_clock::now();
    lImporter->Import(lScene);
    high_resolution_clock::time_point postImport = high_resolution_clock::now();

    // The file is imported; so get rid of the importer.
    lImporter->Destroy();

    // Walk, dumping dumbly
    high_resolution_clock::time_point preWalk = high_resolution_clock::now();
    // .. magic goes here ..
    high_resolution_clock::time_point postWalk = high_resolution_clock::now();

    // Record Times
    double time_init = duration_cast<duration<double>>(postInit-preInit).count() * 1000;
    double time_import = duration_cast<duration<double>>(postImport-preImport).count() * 1000;
    double time_walk = duration_cast<duration<double>>(postWalk-preWalk).count() * 1000;
    printf("\ninit=%f  import=%f  walk=%f\n", time_init, time_import, time_walk);

    // Destroy the SDK manager and all the other objects it was handling.
    lSdkManager->Destroy();
    return 0;
}

extern "C" void foo()
{
    inner_foo();
}
