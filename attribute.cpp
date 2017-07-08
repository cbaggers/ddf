#include "include/enumConversion.h"
#include "include/exporters.h"
#include "include/attribute.h"

//------------------------------------------------------------

static int meshID = -1;

FbxUInt64 VisitMesh(Exporters* exporters, FbxMesh* pMesh)
{
    int id = meshID+=1;
    pMesh->SetUserDataPtr((void*)id);



    return id;
}

//------------------------------------------------------------
// Attributes

FbxUInt64 VisitAttribute(Exporters* exporters, FbxNodeAttribute* pAttribute)
{
    // It is important to know that the id this returns is attribute specific
    if(!pAttribute) return -1;
    if (pAttribute->GetUserDataPtr()!=NULL) return (FbxUInt64)pAttribute->GetUserDataPtr();

    switch (pAttribute->GetAttributeType())
    {
    case FbxNodeAttribute::eUnknown: return -1;
    case FbxNodeAttribute::eNull: return -1;
    case FbxNodeAttribute::eMarker: return -1;
    case FbxNodeAttribute::eSkeleton: return -1;
    case FbxNodeAttribute::eMesh: return VisitMesh(exporters, (FbxMesh*)pAttribute);
    case FbxNodeAttribute::eNurbs: return -1;
    case FbxNodeAttribute::ePatch: return -1;
    case FbxNodeAttribute::eCamera: return -1;
    case FbxNodeAttribute::eCameraStereo: return -1;
    case FbxNodeAttribute::eCameraSwitcher: return -1;
    case FbxNodeAttribute::eLight: return -1;
    case FbxNodeAttribute::eOpticalReference: return -1;
    case FbxNodeAttribute::eOpticalMarker: return -1;
    case FbxNodeAttribute::eNurbsCurve: return -1;
    case FbxNodeAttribute::eTrimNurbsSurface: return -1;
    case FbxNodeAttribute::eBoundary: return -1;
    case FbxNodeAttribute::eNurbsSurface: return -1;
    case FbxNodeAttribute::eShape: return -1;
    case FbxNodeAttribute::eLODGroup: return -1;
    case FbxNodeAttribute::eSubDiv: return -1;
    case FbxNodeAttribute::eCachedEffect: return -1;
    case FbxNodeAttribute::eLine: return -1;
    }
    exit(100);
}

//------------------------------------------------------------
