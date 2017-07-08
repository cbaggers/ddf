#include "include/enumConversion.h"
#include "include/exporters.h"
#include "include/surfacematerial.h"

//------------------------------------------------------------

void ExportDummyPhong(Exporters* exporters)
{
    //ExportBool(false);
    FbxDouble3 specular = FbxSurfacePhong::sSpecularDefault;
    FbxDouble specularFactor = FbxSurfacePhong::sSpecularFactorDefault;
    FbxDouble shininess = FbxSurfacePhong::sShininessDefault;
    FbxDouble3 reflection = FbxSurfacePhong::sReflectionDefault;
    FbxDouble reflectionFactor = FbxSurfacePhong::sReflectionFactorDefault;
}

void ExportDummyLambert(Exporters* exporters)
{
    //ExportBool(false);
    FbxDouble3 emissive = FbxSurfaceLambert::sEmissiveDefault;
    FbxDouble emissiveFactor = FbxSurfaceLambert::sEmissiveFactorDefault;
    FbxDouble3 ambient = FbxSurfaceLambert::sAmbientDefault;
    FbxDouble ambientFactor = FbxSurfaceLambert::sAmbientFactorDefault;
    FbxDouble3 diffuse = FbxSurfaceLambert::sDiffuseDefault;
    FbxDouble diffuseFactor = FbxSurfaceLambert::sDiffuseFactorDefault;
    FbxDouble3 bump = FbxSurfaceLambert::sBumpDefault;
    FbxDouble3 normalMap = FbxSurfaceLambert::sNormalMapDefault;
    FbxDouble bumpFactor = FbxSurfaceLambert::sBumpFactorDefault;
    FbxDouble3 transparent = FbxSurfaceLambert::sTransparentDefault;
    FbxDouble transparencyFactor = FbxSurfaceLambert::sTransparencyFactorDefault;
    FbxDouble3 displacement = FbxSurfaceLambert::sDisplacementDefault;
    FbxDouble displacementFactor = FbxSurfaceLambert::sDisplacementFactorDefault;
    FbxDouble3 vectorDisplacement = FbxSurfaceLambert::sVectorDisplacementDefault;
    FbxDouble vectorDisplacementFactor = FbxSurfaceLambert::sVectorDisplacementFactorDefault;
}

void ExportDummyMaterial(Exporters* exporters)
{
    ExportDummyLambert(exporters);
    ExportDummyPhong(exporters);
}

//------------------------------------------------------------

void ExportSurfacePhong(Exporters* exporters, FbxSurfacePhong* pMaterial)
{
    //ExportBool(true);
    FbxDouble3 specular = pMaterial->Specular.Get();
    FbxDouble specularFactor = pMaterial->SpecularFactor.Get();
    FbxDouble shininess = pMaterial->Shininess.Get();
    FbxDouble3 reflection = pMaterial->Reflection.Get();
    FbxDouble reflectionFactor = pMaterial->ReflectionFactor.Get();
}

void ExportSurfaceLambert(Exporters* exporters, FbxSurfaceLambert* pMaterial)
{
    //ExportBool(true);

    FbxDouble3 emissive = pMaterial->Emissive.Get();
    FbxDouble emissiveFactor = pMaterial->EmissiveFactor.Get();
    FbxDouble3 ambient = pMaterial->Ambient.Get();
    FbxDouble ambientFactor = pMaterial->AmbientFactor.Get();
    FbxDouble3 diffuse = pMaterial->Diffuse.Get();
    FbxDouble diffuseFactor = pMaterial->DiffuseFactor.Get();
    FbxDouble3 normalMap = pMaterial->NormalMap.Get();
    FbxDouble3 bump = pMaterial->Bump.Get();
    FbxDouble bumpFactor = pMaterial->BumpFactor.Get();
    FbxDouble3 transparentColor = pMaterial->TransparentColor.Get();
    FbxDouble transparencyFactor = pMaterial->TransparencyFactor.Get();
    FbxDouble3 displacementColor = pMaterial->DisplacementColor.Get();
    FbxDouble displacementFactor = pMaterial->DisplacementFactor.Get();
    FbxDouble3 vectorDisplacementColor = pMaterial->VectorDisplacementColor.Get();
    FbxDouble vectorDisplacementFactor = pMaterial->VectorDisplacementFactor.Get();


    if (pMaterial->GetClassId().Is(FbxSurfacePhong::ClassId))
    {
        ExportSurfacePhong(exporters, (FbxSurfacePhong*)pMaterial);
    }
    else
    {
        ExportDummyPhong(exporters);
    }
}

//------------------------------------------------------------
// Surface Materials

static int surfaceMaterialID = -1;

FbxUInt64 VisitSurfaceMaterial(Exporters* exporters, FbxSurfaceMaterial* pMaterial)
{
    if(!pMaterial) return false;
    if (pMaterial->GetUserDataPtr()!=NULL) return (FbxUInt64)pMaterial->GetUserDataPtr();

    int id = surfaceMaterialID += 1;
    pMaterial->SetUserDataPtr((void*)id);

    FbxString shadingModel = pMaterial->ShadingModel.Get();
    FbxBool multiLayer = pMaterial->MultiLayer.Get();

    if (pMaterial->GetClassId().Is(FbxSurfaceLambert::ClassId))
    {
        ExportSurfaceLambert(exporters, (FbxSurfaceLambert*)pMaterial);
    }
    else
    {
        ExportDummyMaterial(exporters);
    }

    return id;
}

//------------------------------------------------------------
