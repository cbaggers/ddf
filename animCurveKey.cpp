#include "include/enumConversion.h"
#include "include/exporters.h"
#include "include/animCurveKey.h"

//------------------------------------------------------------
// AnimCurveKey

static FbxUInt64 animCurveKeyID = -1;

FbxUInt64 VisitAnimCurveKey(Exporters* exporters, FbxAnimCurveKey* pAnimCurveKey)
{
    if(!animCurveKeyID) return -1;
    FbxUInt64 id = animCurveKeyID += 1;

    bool keyBreak = pAnimCurveKey->GetBreak();
    float value = pAnimCurveKey->GetValue();
    FbxTime time = pAnimCurveKey->GetTime();

    int constantMode = FbxAnimCurveDefEConstantModeToInt(pAnimCurveKey->GetConstantMode());
    int interpolation = FbxAnimCurveDefEInterpolationTypeToInt(pAnimCurveKey->GetInterpolation());
    int tangentMode = FbxAnimCurveDefETangentModeToInt(pAnimCurveKey->GetTangentMode());
    int tangentVisibility = FbxAnimCurveDefETangentVisibilityToInt(pAnimCurveKey->GetTangentVisibility());
    int tangentVelocityMode = FbxAnimCurveDefEVelocityModeToInt(pAnimCurveKey->GetTangentVelocityMode());
    int tangentWeightMode = FbxAnimCurveDefEWeightedModeToInt(pAnimCurveKey->GetTangentWeightMode());

    float valRightSlope = pAnimCurveKey->GetDataFloat(FbxAnimCurveDef::eRightSlope);
    float valRightWeight = pAnimCurveKey->GetDataFloat(FbxAnimCurveDef::eRightWeight);
    float valRightVelocity = pAnimCurveKey->GetDataFloat(FbxAnimCurveDef::eRightVelocity);
    float valNextLeftSlope = pAnimCurveKey->GetDataFloat(FbxAnimCurveDef::eNextLeftSlope);
    float valNextLeftWeight = pAnimCurveKey->GetDataFloat(FbxAnimCurveDef::eNextLeftWeight);
    float valNextLeftVelocity = pAnimCurveKey->GetDataFloat(FbxAnimCurveDef::eNextLeftVelocity);

    return id;
}
