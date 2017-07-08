#include "include/enumConversion.h"

int InheritTypeToInt(FbxTransform::EInheritType pInheritType)
{
    switch (pInheritType)
    {
    case FbxTransform::eInheritRrSs: return 0;
    case FbxTransform::eInheritRSrs: return 1;
    case FbxTransform::eInheritRrs: return 2;
    }
    exit(2);
}

int EFbxQuatInterpModeToInt(EFbxQuatInterpMode mode)
{
    switch (mode)
    {
    case eQuatInterpOff: return 0;
    case eQuatInterpClassic: return 1;
    case eQuatInterpSlerp: return 2;
    case eQuatInterpCubic: return 3;
    case eQuatInterpTangentDependent: return 4;
    case eQuatInterpCount: return 5;
    }
    exit(3);
}

int EFbxRotationOrderToInt(EFbxRotationOrder order)
{
    switch (order)
    {
    case eEulerXYZ: return 0;
    case eEulerXZY: return 1;
    case eEulerYZX: return 2;
    case eEulerYXZ: return 3;
    case eEulerZXY: return 4;
    case eEulerZYX: return 5;
    case eSphericXYZ: return 6;
    }
    exit(4);
}

int EShadingModeToInt(FbxNode::EShadingMode mode)
{
    switch (mode)
    {
    case FbxNode::eHardShading: return 0;
    case FbxNode::eWireFrame: return 1;
    case FbxNode::eFlatShading: return 2;
    case FbxNode::eLightShading: return 3;
    case FbxNode::eTextureShading: return 4;
    case FbxNode::eFullShading: return 5;
    }
    exit(5);
}
