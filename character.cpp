#include "include/enumConversion.h"
#include "include/exporters.h"
#include "include/character.h"

//------------------------------------------------------------
// Characters

static int characterID = -1;

FbxUInt64 VisitCharacter(Exporters* exporters, FbxCharacter* pCharacter)
{
    if (!pCharacter) return -1;
    if (pCharacter->GetUserDataPtr()!=NULL) return (FbxUInt64)pCharacter->GetUserDataPtr();

    int id = characterID+=1;
    pCharacter->SetUserDataPtr((void*)id);

}

//------------------------------------------------------------
