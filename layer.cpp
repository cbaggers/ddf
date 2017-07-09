#include "include/enumConversion.h"
#include "include/exporters.h"
#include "include/layer.h"

//------------------------------------------------------------

static int layerID = -1;

FbxUInt64 VisitLayer(Exporters* exporters, FbxLayer* pLayer)
{
    if(!pLayer) return -1;
    if (pLayer->GetUserDataPtr()!=NULL) return (FbxUInt64)pLayer->GetUserDataPtr();

    int id = layerID+=1;
    pLayer->SetUserDataPtr((void*)id);

    FbxLayerElementBinormal* binormals = pLayer->GetBinormals();
    FbxLayerElementCrease* edgeCrease = pLayer->GetEdgeCrease();
    FbxLayerElementCrease* vertexCrease = pLayer->GetVertexCrease();
    FbxLayerElementHole* hole = pLayer->GetHole();
    FbxLayerElementMaterial* materials = pLayer->GetMaterials();
    FbxLayerElementNormal* normals = pLayer->GetNormals();
    FbxLayerElementPolygonGroup* polygonGroups = pLayer->GetPolygonGroups();
    FbxLayerElementSmoothing* smoothing = pLayer->GetSmoothing();
    FbxLayerElementTangent* tangents = pLayer->GetTangents();
    FbxLayerElementUserData* userData = pLayer->GetUserData();
    FbxLayerElementVertexColor* vertexColors = pLayer->GetVertexColors();
    FbxLayerElementVisibility* visibility = pLayer->GetVisibility();

    // FbxLayerElementTexture* textures = pLayer->GetTextures(FbxLayerElement::EType pType);
    // FbxLayerElementUV* GetUVs(FbxLayerElement::EType pTypeIdentifier=FbxLayerElement::eTextureDiffuse)
    // int GetUVSetCount()
    // FbxArray< FbxLayerElementUV* > GetUVSets()
    // FbxArray< FbxLayerElement::EType > GetUVSetChannels()
    // FbxLayerElement* GetLayerElementOfType(FbxLayerElement::EType pType, bool pIsUV=false)

    return id;
}

//------------------------------------------------------------
