#include "include/enumConversion.h"
#include "include/exporters.h"
#include "include/animStack.h"
#include "include/animLayer.h"

//------------------------------------------------------------
// AnimStacks

static FbxUInt64 animStackID = -1;

FbxUInt64 VisitAnimStack(Exporters* exporters, FbxAnimStack* pAnimStack)
{
    if(!pAnimStack) return -1;
    if (pAnimStack->GetUserDataPtr()!=NULL) return (FbxUInt64)pAnimStack->GetUserDataPtr();

    FbxUInt64 id = animStackID += 1;
    pAnimStack->SetUserDataPtr((void*)id);

    FbxString description = pAnimStack->Description.Get();
    FbxTime localStart = pAnimStack->LocalStart.Get();
    FbxTime localStop = pAnimStack->LocalStop.Get();
    FbxTime referenceStart = pAnimStack->ReferenceStart.Get();
    FbxTime referenceStop = pAnimStack->ReferenceStop.Get();

    int numAnimLayers = pAnimStack->GetMemberCount<FbxAnimLayer>();
    for (int animLayer=0; animLayer<numAnimLayers; animLayer++) {
        FbxAnimLayer* pAnimLayer = pAnimStack->GetMember<FbxAnimLayer>(animLayer);
        VisitAnimLayer(exporters, pAnimLayer);
    }

    return id;
}
