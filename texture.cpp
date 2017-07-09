#include "include/enumConversion.h"
#include "include/exporters.h"
#include "include/texture.h"

//------------------------------------------------------------
// Textures

static int textureID = -1;

FbxUInt64 VisitTexture(Exporters* exporters, FbxTexture* pTexture)
{
    if(!pTexture) return false;
    if (pTexture->GetUserDataPtr()!=NULL) return (FbxUInt64)pTexture->GetUserDataPtr();

    int id = textureID += 1;
    pTexture->SetUserDataPtr((void*)id);

    // something!

    return id;
}

//------------------------------------------------------------
