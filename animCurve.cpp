#include "include/enumConversion.h"
#include "include/exporters.h"
#include "include/animCurve.h"

//------------------------------------------------------------
// AnimCurve

static FbxUInt64 animCurveID = -1;

FbxUInt64 VisitAnimCurve(Exporters* exporters, FbxAnimCurve* pAnimCurve)
{
    if(!pAnimCurve) return -1;
    if (pAnimCurve->GetUserDataPtr()!=NULL) return (FbxUInt64)pAnimCurve->GetUserDataPtr();

    FbxUInt64 id = animCurveID += 1;
    pAnimCurve->SetUserDataPtr((void*)id);

    int keyCount = pAnimCurve->KeyGetCount();
    for (int keyIndex = 0; keyIndex < keyCount; keyIndex++)
    {
        // Each key defines tangents and interpolation that modify the
        // animation curve. Tangents control the way the animation
        // curve enters and exits the keys. Interpolation indicates
        // the animation curve's behavior between keys.

        FbxAnimCurveKey key = pAnimCurve->KeyGet(keyIndex);

        float keyValue = pAnimCurve->KeyGetValue(keyIndex);

        bool keyBreak = pAnimCurve->KeyGetBreak(keyIndex);
        bool keyIsLeftTangentWeighted = pAnimCurve->KeyIsLeftTangentWeighted(keyIndex);
        bool keyIsRightTangentWeighted = pAnimCurve->KeyIsRightTangentWeighted(keyIndex);

        float keyLeftAuto = pAnimCurve->KeyGetLeftAuto(keyIndex);
        float keyLeftDerivative = pAnimCurve->KeyGetLeftDerivative(keyIndex);
        float keyLeftTangentVelocity = pAnimCurve->KeyGetLeftTangentVelocity(keyIndex);
        float keyLeftTangentWeight = pAnimCurve->KeyGetLeftTangentWeight(keyIndex);
        float keyRightAuto = pAnimCurve->KeyGetRightAuto(keyIndex);
        float keyRightDerivative = pAnimCurve->KeyGetRightDerivative(keyIndex);
        float keyRightTangentVelocity = pAnimCurve->KeyGetRightTangentVelocity(keyIndex);
        float keyRightTangentWeight = pAnimCurve->KeyGetRightTangentWeight(keyIndex);

        int keyConstantMode = FbxAnimCurveDefEConstantModeToInt(pAnimCurve->KeyGetConstantMode(keyIndex));
        int interpolationType = FbxAnimCurveDefEInterpolationTypeToInt(pAnimCurve->KeyGetInterpolation(keyIndex));
        int tangentMode = FbxAnimCurveDefETangentModeToInt(pAnimCurve->KeyGetTangentMode(keyIndex));

        FbxTime keyTime = pAnimCurve->KeyGetTime(keyIndex);

        FbxAnimCurveTangentInfo keyLeftDerivativeInfo = pAnimCurve->KeyGetLeftDerivativeInfo(keyIndex);
        FbxAnimCurveTangentInfo keyRightDerivativeInfo = pAnimCurve->KeyGetRightDerivativeInfo(keyIndex);
        // {TODO} what to do with these?
    }

    return id;
}
