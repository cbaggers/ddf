#include "include/enumConversion.h"
#include "include/exporters.h"
#include "include/texture.h"
#include "include/blob.h"

//------------------------------------------------------------
// Textures

static FbxUInt64 textureID = -1;

FbxUInt64 VisitTexture(Exporters* exporters, FbxTexture* pTexture)
{
    // {TODO} this needs object

    if(!pTexture) return -1;
    if (pTexture->GetUserDataPtr()!=NULL) return (FbxUInt64)pTexture->GetUserDataPtr();

    FbxUInt64 id = textureID += 1;
    pTexture->SetUserDataPtr((void*)id);

    FbxBool premultiplyAlpha = pTexture->PremultiplyAlpha.Get();
    FbxBool uvSwap = pTexture->UVSwap.Get();
    FbxDouble alpha = pTexture->Alpha.Get();
    FbxDouble3 rotation = pTexture->Rotation.Get();
    FbxDouble3 rotationPivot = pTexture->RotationPivot.Get();
    FbxDouble3 scaling = pTexture->Scaling.Get();
    FbxDouble3 scalingPivot = pTexture->ScalingPivot.Get();
    FbxDouble3 translation = pTexture->Translation.Get();
    FbxString uvSet = pTexture->UVSet.Get();

    int currentTextureBlendMode = TextureEBlendModeToInt(pTexture->CurrentTextureBlendMode.Get());
    int textureTypeUse = TextureETextureUse6ToInt(pTexture->TextureTypeUse.Get());
    int currentMappingType = TextureEUnifiedMappingTypeToInt(pTexture->CurrentMappingType.Get());
    int wrapModeU = TextureEWrapModeToInt(pTexture->WrapModeU.Get());
    int wrapModeV = TextureEWrapModeToInt(pTexture->WrapModeV.Get());

    bool swapUV = pTexture->GetSwapUV();
    int croppingBottom = pTexture->GetCroppingBottom();
    int croppingLeft = pTexture->GetCroppingLeft();
    int croppingRight = pTexture->GetCroppingRight();
    int croppingTop = pTexture->GetCroppingTop();
    double defaultAlpha = pTexture->GetDefaultAlpha();
    double rotationU = pTexture->GetRotationU();
    double rotationV = pTexture->GetRotationV();
    double rotationW = pTexture->GetRotationW();
    double scaleU = pTexture->GetScaleU();
    double scaleV = pTexture->GetScaleV();
    double translationU = pTexture->GetTranslationU();
    double translationV = pTexture->GetTranslationV();

    int alphaSource = TextureEAlphaSourceToInt(pTexture->GetAlphaSource());
    int blendMode = TextureEBlendModeToInt(pTexture->GetBlendMode());
    int mappingType = TextureEMappingTypeToInt(pTexture->GetMappingType());
    int planarMappingNormal = TextureEPlanarMappingNormalToInt(pTexture->GetPlanarMappingNormal());
    int textureUse = TextureETextureUseToInt(pTexture->GetTextureUse());

    // {TODO} what do we do with these?
    // FbxVector4& GetDefaultT (FbxVector4 &pT)
    // FbxVector4& GetDefaultR (FbxVector4 &pR)
    // FbxVector4& GetDefaultS (FbxVector4 &pS)

    if (pTexture->GetClassId().Is(FbxFileTexture::ClassId))
    {
        // ExportInt(0);
        FbxFileTexture* pFileTexture = (FbxFileTexture*)pTexture;
        FbxBool useMaterial = pFileTexture->UseMaterial.Get();
        FbxBool useMipMap = pFileTexture->UseMipMap.Get();
        const char* fileName = pFileTexture->GetFileName();
        const char* relativeFileName = pFileTexture->GetRelativeFileName();
    }
    else if (pTexture->GetClassId().Is(FbxLayeredTexture::ClassId))
    {
        // ExportInt(1);
        FbxLayeredTexture* pLayeredTexture = (FbxLayeredTexture*)pTexture;

        for(int pIndex=0; pIndex<pTexture->GetSrcObjectCount<FbxTexture>(); ++pIndex)
        {
            FbxLayeredTexture::EBlendMode pMode;
            double pAlpha;
            int blendMode = -1;
            int alphaMode = -1;
            if (pLayeredTexture->GetTextureBlendMode(pIndex, pMode))
            {
                blendMode = LayeredTextureEBlendModeToInt(pMode);
            }
            if (pLayeredTexture->GetTextureAlpha(pIndex, pAlpha))
            {
                alphaMode = pAlpha;
            }
        }
    }
    else if (pTexture->GetClassId().Is(FbxProceduralTexture::ClassId))
    {
        // ExportInt(2);
        FbxProceduralTexture* pProcTexture = (FbxProceduralTexture*)pTexture;
        int blobID = VisitBlob(exporters, pProcTexture->GetBlob());
    }
    else
    {
        exit(201);
    }


    return id;
}

//------------------------------------------------------------
