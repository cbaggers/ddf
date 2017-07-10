#include "include/enumConversion.h"
#include "include/exporters.h"
#include "include/animCurveNode.h"

//------------------------------------------------------------
// AnimCurveNode

static FbxUInt64 animCurveNodeID = -1;

FbxUInt64 VisitAnimCurveNode(Exporters* exporters, FbxAnimCurveNode* pAnimCurveNode)
{
    if(!pAnimCurveNode) return -1;
    if (pAnimCurveNode->GetUserDataPtr()!=NULL) return (FbxUInt64)pAnimCurveNode->GetUserDataPtr();

    FbxUInt64 id = animCurveNodeID += 1;
    pAnimCurveNode->SetUserDataPtr((void*)id);


    bool isAnimated = pAnimCurveNode->IsAnimated(false);
    bool isAnimatedRecursive = pAnimCurveNode->IsAnimated(true);
    bool isComposite = pAnimCurveNode->IsComposite();

    FbxTimeSpan pTimeInterval;
    if (pAnimCurveNode->GetAnimationInterval(pTimeInterval))
    {
        // {TODO} Export the time interval
    }
    else
    {
        printf("animation has no interval.. Im just gonna exit for now, this might be a {TODO}");
        exit(301);
    }

    // Some notes from the docs
    //
    // The FBX SDK animation system's default implementation is to
    // consider only the first curve connected to the
    // channel. Therefore, if the caller connects multiple animation
    // curves to the same channel, then it becomes the caller's
    // responsibility to handle and manipulate these extra curves in a
    // meaningful manner.
    //
    // The number of channels matches the number of values the property we are animating has
    //
    unsigned int channelCount = pAnimCurveNode->GetChannelsCount();
    for (unsigned int channelIndex=0; channelIndex < channelCount; channelIndex++)
    {
        // usually this will be 1
        int curveCount = pAnimCurveNode->GetCurveCount(channelIndex);
        for (int curveIndex = 0; curveIndex < curveCount; curveIndex++)
        {
            FbxAnimCurve* curve = pAnimCurveNode->GetCurve(channelIndex, curveIndex);
        }
    }

    return id;
}
