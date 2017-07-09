#include "include/enumConversion.h"
#include "include/exporters.h"
#include "include/layer.h"

//------------------------------------------------------------

void ExportIntTemplateArray(FbxLayerElementArrayTemplate<int>& arr)
{
    int len = arr.GetCount();
    for (int i = 0; i < len; i++) {
        int ID = arr[i];
    }
}

void ExportIndexToDirectTemplateArray(FbxLayerElementArrayTemplate<int>& arr)
{
    ExportIntTemplateArray(arr);
}

void ExportBoolTemplateArray(FbxLayerElementArrayTemplate<bool>& arr)
{
    int len = arr.GetCount();
    for (int i = 0; i < len; i++) {
        bool val = arr[i];
    }
}

void ExportDoubleTemplateArray(FbxLayerElementArrayTemplate<double>& arr)
{
    int len = arr.GetCount();
    for (int i = 0; i < len; i++) {
        double val = arr[i];
    }
}

void ExportFbxVector2TemplateArray(FbxLayerElementArrayTemplate<FbxVector2>& arr)
{
    int len = arr.GetCount();
    for (int i = 0; i < len; i++) {
        FbxVector2 v4 = arr[i];
    }
}

void ExportFbxVector4TemplateArray(FbxLayerElementArrayTemplate<FbxVector4>& arr)
{
    int len = arr.GetCount();
    for (int i = 0; i < len; i++) {
        FbxVector4 v4 = arr[i];
    }
}

void ExportFbxColorTemplateArray(FbxLayerElementArrayTemplate<FbxColor>& arr)
{
    int len = arr.GetCount();
    for (int i = 0; i < len; i++) {
        FbxColor v4 = arr[i];
    }
}

//------------------------------------------------------------

static int layerBinormalsID = -1;

FbxUInt64 VisitBinormals (Exporters* exporters, FbxLayerElementBinormal* binormals)
{
    if(!binormals) return -1;
    // no userdata field
    FbxUInt64 id = layerBinormalsID+=1;

    int mappingMode = LayerElementMappingModeToInt(binormals->GetMappingMode());
    int referenceMode = LayerElementReferenceModeToInt(binormals->GetReferenceMode());
    if (referenceMode==0) // direct
    {
        ExportFbxVector4TemplateArray(binormals->GetDirectArray());
    }
    else // index
    {
        ExportIndexToDirectTemplateArray(binormals->GetIndexArray());
    }

    return id;
}

//------------------------------------------------------------

static int layerEdgeCreaseID = -1;

FbxUInt64 VisitEdgeCrease (Exporters* exporters, FbxLayerElementCrease* creases)
{
    if(!creases) return -1;
    // no userdata field
    FbxUInt64 id = layerEdgeCreaseID+=1;

    int mappingMode = LayerElementMappingModeToInt(creases->GetMappingMode());
    int referenceMode = LayerElementReferenceModeToInt(creases->GetReferenceMode());
    if (referenceMode==0) // direct
    {
        ExportDoubleTemplateArray(creases->GetDirectArray());
    }
    else // index
    {
        ExportIndexToDirectTemplateArray(creases->GetIndexArray());
    }

    return id;
}

//------------------------------------------------------------

static int layerVertexCreaseID = -1;

FbxUInt64 VisitVertexCrease (Exporters* exporters, FbxLayerElementCrease* creases)
{
    if(!creases) return -1;
    // no userdata field
    FbxUInt64 id = layerVertexCreaseID+=1;

    int mappingMode = LayerElementMappingModeToInt(creases->GetMappingMode());
    int referenceMode = LayerElementReferenceModeToInt(creases->GetReferenceMode());
    if (referenceMode==0) // direct
    {
        ExportDoubleTemplateArray(creases->GetDirectArray());
    }
    else // index
    {
        ExportIndexToDirectTemplateArray(creases->GetIndexArray());
    }

    return id;
}

//------------------------------------------------------------

static int layerHoleID = -1;

FbxUInt64 VisitHole (Exporters* exporters, FbxLayerElementHole* holes)
{
    if(!holes) return -1;
    // no userdata field
    FbxUInt64 id = layerHoleID+=1;

    int mappingMode = LayerElementMappingModeToInt(holes->GetMappingMode());
    int referenceMode = LayerElementReferenceModeToInt(holes->GetReferenceMode());
    if (referenceMode==0) // direct
    {
        ExportBoolTemplateArray(holes->GetDirectArray());
    }
    else // index
    {
        ExportIndexToDirectTemplateArray(holes->GetIndexArray());
    }

    return id;
}

//------------------------------------------------------------

static int layerMaterialID = -1;

FbxUInt64 VisitMaterials (Exporters* exporters, FbxLayerElementMaterial* material)
{
    if(!material) return -1;
    // no userdata field
    FbxUInt64 id = layerMaterialID+=1;

    int mappingMode = LayerElementMappingModeToInt(material->GetMappingMode());
    // even though the only option is eIndexToDirect write this as it makes
    // code reuse in the loaders easier
    int referenceMode = LayerElementReferenceModeToInt(material->GetReferenceMode());
    if (referenceMode==0) // direct
    {
        // FBX SDK 2011 and later connects materials (FbxSurfaceMaterial)
        // to nodes (FbxNode). The direct array of this class is no longer used.
        // The integer "n" in the index array of this class represents the n-th
        // material (zero-based) connected to the node.

        //ExportInt(0);
    }
    else // index
    {
        ExportIndexToDirectTemplateArray(material->GetIndexArray());
    }
    return id;
}

//------------------------------------------------------------

static int layerNormalsID = -1;

FbxUInt64 VisitNormals (Exporters* exporters, FbxLayerElementNormal* normals)
{
    if(!normals) return -1;
    // no userdata field
    FbxUInt64 id = layerNormalsID+=1;

    int mappingMode = LayerElementMappingModeToInt(normals->GetMappingMode());
    // even though the only option is eIndexToDirect write this as it makes
    // code reuse in the loaders easier
    int referenceMode = LayerElementReferenceModeToInt(normals->GetReferenceMode());
    if (referenceMode==0) // direct
    {
        // To be correctly saved in FBX file, this type of Layer element
        // should have its reference mode set to eIndexToDirect.

        //ExportInt(0);
    }
    else // index
    {
        ExportIndexToDirectTemplateArray(normals->GetIndexArray());
    }

    return id;
}

//------------------------------------------------------------

static int layerPolygonGroupID = -1;

FbxUInt64 VisitPolygonGroups (Exporters* exporters, FbxLayerElementPolygonGroup* material)
{
    if(!material) return -1;
    // no userdata field
    FbxUInt64 id = layerPolygonGroupID+=1;

    int mappingMode = LayerElementMappingModeToInt(material->GetMappingMode());
    // even though the only option is eIndexToDirect write this as it makes
    // code reuse in the loaders easier
    int referenceMode = LayerElementReferenceModeToInt(material->GetReferenceMode());
    if (referenceMode==0) // direct
    {
        //ExportInt(0);
    }
    else // index
    {
        ExportIndexToDirectTemplateArray(material->GetIndexArray());
    }
    return id;
}

//------------------------------------------------------------

static int layerSmoothingID = -1;

FbxUInt64 VisitSmoothing (Exporters* exporters, FbxLayerElementSmoothing* smoothing)
{
    if(!smoothing) return -1;
    // no userdata field
    FbxUInt64 id = layerSmoothingID+=1;

    int mappingMode = LayerElementMappingModeToInt(smoothing->GetMappingMode());
    // even though the only option is eDirect write this as it makes
    // code reuse in the loaders easier
    int referenceMode = LayerElementReferenceModeToInt(smoothing->GetReferenceMode());
    if (referenceMode==0) // direct
    {
        ExportIntTemplateArray(smoothing->GetIndexArray());
    }
    else // index
    {
        //ExportInt(0);
    }
    return id;
}

//------------------------------------------------------------

static int layerTangentsID = -1;

FbxUInt64 VisitTangents (Exporters* exporters, FbxLayerElementTangent* tangents)
{
    if(!tangents) return -1;
    // no userdata field
    FbxUInt64 id = layerTangentsID+=1;

    int mappingMode = LayerElementMappingModeToInt(tangents->GetMappingMode());
    int referenceMode = LayerElementReferenceModeToInt(tangents->GetReferenceMode());
    if (referenceMode==0) // direct
    {
        ExportFbxVector4TemplateArray(tangents->GetDirectArray());
    }
    else // index
    {
        ExportIndexToDirectTemplateArray(tangents->GetIndexArray());
    }

    return id;
}

//------------------------------------------------------------

FbxUInt64 VisitUserData (Exporters* exporters, FbxLayerElementUserData* foo)
{
    // we ignore user data as would require custom exporters and this is
    // the dumb fbx dump, and by god we will keep it dumb
    return -1;
}

//------------------------------------------------------------

static int layerVertexColorsID = -1;

FbxUInt64 VisitVertexColors (Exporters* exporters, FbxLayerElementVertexColor* colors)
{
    if(!colors) return -1;
    // no userdata field
    FbxUInt64 id = layerVertexColorsID+=1;

    int mappingMode = LayerElementMappingModeToInt(colors->GetMappingMode());
    int referenceMode = LayerElementReferenceModeToInt(colors->GetReferenceMode());
    if (referenceMode==0) // direct
    {
        ExportFbxColorTemplateArray(colors->GetDirectArray());
    }
    else // index
    {
        ExportIndexToDirectTemplateArray(colors->GetIndexArray());
    }

    return id;
}

//------------------------------------------------------------

static int layerVisibilityID = -1;

FbxUInt64 VisitVisibility (Exporters* exporters, FbxLayerElementVisibility* visibility)
{
    if(!visibility) return -1;
    // no userdata field
    FbxUInt64 id = layerVisibilityID+=1;

    int mappingMode = LayerElementMappingModeToInt(visibility->GetMappingMode());
    int referenceMode = LayerElementReferenceModeToInt(visibility->GetReferenceMode());
    if (referenceMode==0) // direct
    {
        ExportBoolTemplateArray(visibility->GetDirectArray());
    }
    else // index
    {
        ExportIndexToDirectTemplateArray(visibility->GetIndexArray());
    }

    return id;
}

//------------------------------------------------------------

static int layerUVSetID = -1;

FbxUInt64 VisitUVSet (Exporters* exporters, const FbxLayerElementUV* uvs)
{
    // The FbxLayerElementUV class represents a UV set belonging
    // to the geometry. Each UV set in a geometry has a name to
    // identify itself. The string property FbxTexture.UVSet
    // indicates the UV set to use.
    if(!uvs) return -1;
    // no userdata field
    FbxUInt64 id = layerUVSetID+=1;

    int mappingMode = LayerElementMappingModeToInt(uvs->GetMappingMode());
    int referenceMode = LayerElementReferenceModeToInt(uvs->GetReferenceMode());
    if (referenceMode==0) // direct
    {
        ExportFbxVector2TemplateArray(uvs->GetDirectArray());
    }
    else // index
    {
        ExportIndexToDirectTemplateArray(uvs->GetIndexArray());
    }

    return id;
}

static int layerUVSetsID = -1;

FbxUInt64 VisitUVSets (Exporters* exporters, FbxArray<const FbxLayerElementUV*>& uvSets)
{
    if(!uvSets) return -1;
    // no userdata field
    FbxUInt64 id = layerUVSetsID+=1;

    int len = uvSets.Size();
    for (int i = 0; i < len; i++) {
        const FbxLayerElementUV* elem = uvSets[i];
        VisitUVSet(exporters, elem);
    }
    return id;
}

//------------------------------------------------------------

static int layerID = -1;

FbxUInt64 VisitLayer(Exporters* exporters, FbxLayer* pLayer)
{
    // has no userdata so cant dedup here yet
    if(!pLayer) return -1;
    int id = layerID+=1;

    int binormalID = VisitBinormals(exporters, pLayer->GetBinormals());
    int edgeCreaseID = VisitEdgeCrease(exporters, pLayer->GetEdgeCrease());
    int vertexCreaseID = VisitVertexCrease(exporters, pLayer->GetVertexCrease());
    int holeID = VisitHole(exporters, pLayer->GetHole());
    int materialsID = VisitMaterials(exporters, pLayer->GetMaterials());
    int normalsID = VisitNormals(exporters, pLayer->GetNormals());
    int polygonGroupsID = VisitPolygonGroups(exporters, pLayer->GetPolygonGroups());
    int smoothingID = VisitSmoothing(exporters, pLayer->GetSmoothing());
    int tangentsID = VisitTangents(exporters, pLayer->GetTangents());
    int userDataID = VisitUserData(exporters, pLayer->GetUserData());
    int vertexColorsID = VisitVertexColors(exporters, pLayer->GetVertexColors());
    int visibilityID = VisitVisibility(exporters, pLayer->GetVisibility());
    FbxArray<const FbxLayerElementUV*> uvSets = pLayer->GetUVSets();
    int uvsID = VisitUVSets(exporters, uvSets);
    // FbxLayerElementTexture is deprecated so we ignore pLayer->GetTextures

    return id;
}

//------------------------------------------------------------
