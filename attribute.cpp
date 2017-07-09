#include "include/enumConversion.h"
#include "include/exporters.h"
#include "include/attribute.h"
#include "include/layer.h"

//------------------------------------------------------------

static int meshID = -1;

FbxUInt64 VisitMesh(Exporters* exporters, FbxMesh* pMesh)
{
    int id = meshID+=1;
    pMesh->SetUserDataPtr((void*)id);

    FbxStatus pStatus;
    int controlPointCount = pMesh->GetControlPointsCount();
    FbxVector4* controlPoints = pMesh->GetControlPoints(&pStatus);

    // Control points
    for (int i = 0; i < controlPointCount; i++)
    {
        FbxVector4 point = *controlPoints;
        controlPoints++;
    }

    int layerCount = pMesh->GetLayerCount();
    for (int layerIndex = 0; layerIndex < layerCount; layerIndex++) {
        FbxLayer* layer = pMesh->GetLayer(layerIndex);
        FbxUInt64 layerID = VisitLayer(exporters, layer);
    }



    // // Polygon
    // int polygonCount = pMesh->GetPolygonCount();
    // for (int polyIndex = 0; polyIndex < polygonCount; polyIndex++)
    // {
    //     int polyGroup = pMesh->GetPolygonGroup(polyIndex);
    //     int polySize = pMesh->GetPolygonSize(polyIndex);
    //     for (int vertIndex = 0; vertIndex < polySize; vertIndex++)
    //     {
    //         int index = pMesh->GetPolygonVertex(polyIndex, vertIndex);
    //         FbxVector4 normal;
    //         if (pMesh->GetPolygonVertexNormal (polyIndex, vertIndex, normal))
    //         {
    //
    //         }
    //         else
    //         {
    //
    //         }
    //         bool isUnmapped;
    //         const char* uvSetName = NULL;
    //         FbxVector2 uv = FbxVector2(0.0f,0.0f);
    //         if (!pMesh->GetPolygonVertexUV(polyIndex, vertIndex, uvSetName, uv, isUnmapped))
    //         {
    //             // This function return true if the specified polygon
    //             // vertex does not have an associated UV. In this
    //             // case, pUnampped is set to true and the content of
    //             // pUV is undefined.
    //         }
    //         else
    //         {
    //
    //         }
    //     }
    // }

    return id;
}

// bool GetTextureUV (FbxLayerElementArrayTemplate< FbxVector2 > **pLockableArray, FbxLayerElement::EType pTypeIdentifier=FbxLayerElement::eTextureDiffuse) const
// bool GetMaterialIndices (FbxLayerElementArrayTemplate< int > **pLockableArray) const
// bool GetTextureIndices (FbxLayerElementArrayTemplate< int > **pLockableArray, FbxLayerElement::EType pTextureType) const

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
