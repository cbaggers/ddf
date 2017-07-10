#include "include/enumConversion.h"
#include "include/exporters.h"
#include "include/globalSettings.h"
#include "include/scene.h"
#include "include/node.h"

//------------------------------------------------------------
// Textures

static int textureID = -1;

FbxUInt64 VisitScene(Exporters* exporters, FbxScene* pScene)
{
    if(!pScene) return false;
    if (pScene->GetUserDataPtr()!=NULL) return (FbxUInt64)pScene->GetUserDataPtr();

    int id = textureID += 1;
    pScene->SetUserDataPtr((void*)id);

    // Global Settings
    VisitGlobalSettings(exporters, &pScene->GetGlobalSettings());

    // Nodes
    FbxNode* pRootNode = pScene->GetRootNode();
    for(int i = 0; i < pRootNode->GetChildCount(); i++)
    {
        VisitNode(exporters, pRootNode->GetChild(i));
    }

    return 0;
}
