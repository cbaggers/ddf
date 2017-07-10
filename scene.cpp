#include "include/enumConversion.h"
#include "include/exporters.h"
#include "include/character.h"
#include "include/globalSettings.h"
#include "include/scene.h"
#include "include/node.h"

//------------------------------------------------------------
// Textures

static FbxUInt64 textureID = -1;

FbxUInt64 VisitScene(Exporters* exporters, FbxScene* pScene)
{
    if(!pScene) return false;
    if (pScene->GetUserDataPtr()!=NULL) return (FbxUInt64)pScene->GetUserDataPtr();

    FbxUInt64 id = textureID += 1;
    pScene->SetUserDataPtr((void*)id);

    // Global Settings
    VisitGlobalSettings(exporters, &pScene->GetGlobalSettings());

    // Nodes
    // We dont visit the root node as it should have no attributes
    FbxNode* pRootNode = pScene->GetRootNode();
    for(int i = 0; i < pRootNode->GetChildCount(); i++)
    {
        VisitNode(exporters, pRootNode->GetChild(i));
    }

    // Characters
    for(int i = 0; i < pScene->GetCharacterCount(); i++)
    {
        VisitCharacter(exporters, pScene->GetCharacter(i));
    }

    return 0;
}
