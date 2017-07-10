#include "include/enumConversion.h"
#include "include/exporters.h"
#include "include/animLayer.h"
#include "include/animCurveNode.h"

//------------------------------------------------------------
// AnimLayer

static FbxUInt64 animLayerID = -1;

FbxUInt64 VisitAnimLayer(Exporters* exporters, FbxAnimLayer* pAnimLayer)
{
    if(!pAnimLayer) return -1;
    if (pAnimLayer->GetUserDataPtr()!=NULL) return (FbxUInt64)pAnimLayer->GetUserDataPtr();

    FbxUInt64 id = animLayerID += 1;
    pAnimLayer->SetUserDataPtr((void*)id);

    FbxDouble weight = pAnimLayer->Weight.Get();
    FbxBool mute = pAnimLayer->Mute.Get();
    FbxBool solo = pAnimLayer->Solo.Get();
    FbxBool lock = pAnimLayer->Lock.Get();
    FbxDouble3 color = pAnimLayer->Color.Get();
    FbxEnum blendMode = pAnimLayer->BlendMode.Get();
    FbxEnum rotationAccumulationMode = pAnimLayer->RotationAccumulationMode.Get();
    FbxEnum scaleAccumulationMode = pAnimLayer->ScaleAccumulationMode.Get();

    // EFbxType pType;
    // bool blendModeBypass = pAnimLayer->GetBlendModeBypass(pType);

    int numAnimLayers = pAnimLayer->GetMemberCount<FbxAnimCurveNode>();
    for (int animLayer=0; animLayer<numAnimLayers; animLayer++)
    {
        FbxAnimCurveNode* pAnimCurveNode = pAnimLayer->GetMember<FbxAnimCurveNode>(animLayer);
        VisitAnimCurveNode(exporters, pAnimCurveNode);
    }

    return id;
}
