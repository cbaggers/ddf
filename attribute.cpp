#include "include/enumConversion.h"
#include "include/exporters.h"
#include "include/attribute.h"
#include "include/layer.h"
#include "include/texture.h"

//------------------------------------------------------------
// Camera

static FbxUInt64 skeletonID = -1;

FbxUInt64 VisitSkeleton(Exporters* exporters, FbxSkeleton* pSkeleton)
{
    // early out check already done in VisitAttribute
    FbxUInt64 id = skeletonID+=1;
    pSkeleton->SetUserDataPtr((void*)id);

    int typeID = SkeletonEtypeToInt(pSkeleton->GetSkeletonType());
    int typeDefaultValueID = SkeletonEtypeToInt(pSkeleton->GetSkeletonTypeDefaultValue());

    bool getLimbNodeColorIsSet = pSkeleton->GetLimbNodeColorIsSet();
    bool getSkeletonTypeIsSet = pSkeleton->GetSkeletonTypeIsSet();
    bool isSkeletonRoot = pSkeleton->IsSkeletonRoot();
    double getLimbLengthDefaultValue = pSkeleton->GetLimbLengthDefaultValue();
    double getLimbNodeSizeDefaultValue = pSkeleton->GetLimbNodeSizeDefaultValue();
    FbxColor getLimbNodeColor = pSkeleton->GetLimbNodeColor();
    FbxColor getLimbNodeColorDefaultValue = pSkeleton->GetLimbNodeColorDefaultValue();

    FbxDouble size = pSkeleton->Size.Get();
    FbxDouble limbLength = pSkeleton->LimbLength.Get();

    return id;
}

//------------------------------------------------------------
// Camera

static FbxUInt64 lightID = -1;

FbxUInt64 VisitLight(Exporters* exporters, FbxLight* pLight)
{
    // early out check already done in VisitAttribute
    FbxUInt64 id = lightID+=1;
    pLight->SetUserDataPtr((void*)id);

    FbxBool castLight = pLight->CastLight.Get();
    FbxBool castShadows = pLight->CastShadows.Get();
    FbxBool drawFrontFacingVolumetricLight = pLight->DrawFrontFacingVolumetricLight.Get();
    FbxBool drawGroundProjection = pLight->DrawGroundProjection.Get();
    FbxBool drawVolumetricLight = pLight->DrawVolumetricLight.Get();
    FbxBool enableBarnDoor = pLight->EnableBarnDoor.Get();
    FbxBool enableFarAttenuation = pLight->EnableFarAttenuation.Get();
    FbxBool enableNearAttenuation = pLight->EnableNearAttenuation.Get();
    FbxDouble decayStart = pLight->DecayStart.Get();
    FbxDouble farAttenuationEnd = pLight->FarAttenuationEnd.Get();
    FbxDouble farAttenuationStart = pLight->FarAttenuationStart.Get();
    FbxDouble fog = pLight->Fog.Get();
    FbxDouble innerAngle = pLight->InnerAngle.Get();
    FbxDouble intensity = pLight->Intensity.Get();
    FbxDouble nearAttenuationEnd = pLight->NearAttenuationEnd.Get();
    FbxDouble nearAttenuationStart = pLight->NearAttenuationStart.Get();
    FbxDouble outerAngle = pLight->OuterAngle.Get();
    FbxDouble3 color = pLight->Color.Get();
    FbxDouble3 shadowColor = pLight->ShadowColor.Get();
    FbxFloat bottomBarnDoor = pLight->BottomBarnDoor.Get();
    FbxFloat leftBarnDoor = pLight->LeftBarnDoor.Get();
    FbxFloat rightBarnDoor = pLight->RightBarnDoor.Get();
    FbxFloat topBarnDoor = pLight->TopBarnDoor.Get();
    FbxString fileName = pLight->FileName.Get();
    int areaLightShape = LightEAreaLightShapeToInt(pLight->AreaLightShape.Get());
    int decayType = LightEDecayTypeToInt(pLight->DecayType.Get());
    int lightType = LightETypeToInt(pLight->LightType.Get());
    FbxUInt64 shadowTextureID = VisitTexture(exporters, pLight->GetShadowTexture());

    return id;
}

//------------------------------------------------------------
// Camera

static FbxUInt64 cameraID = -1;

FbxUInt64 VisitCamera(Exporters* exporters, FbxCamera* pCamera)
{
    // early out check already done in VisitAttribute
    FbxUInt64 id = cameraID+=1;
    pCamera->SetUserDataPtr((void*)id);

    FbxBool autoComputeClipPlanes = pCamera->AutoComputeClipPlanes.Get();
    FbxBool backPlateCenter = pCamera->BackPlateCenter.Get();
    FbxBool backPlateCrop = pCamera->BackPlateCrop.Get();
    FbxBool backPlateFitImage = pCamera->BackPlateFitImage.Get();
    FbxBool backPlateKeepRatio = pCamera->BackPlateKeepRatio.Get();
    FbxBool displaySafeArea = pCamera->DisplaySafeArea.Get();
    FbxBool displaySafeAreaOnRender = pCamera->DisplaySafeAreaOnRender.Get();
    FbxBool displayTurnTableIcon = pCamera->DisplayTurnTableIcon.Get();
    FbxBool frontPlateCenter = pCamera->FrontPlateCenter.Get();
    FbxBool frontPlateCrop = pCamera->FrontPlateCrop.Get();
    FbxBool frontPlateFitImage = pCamera->FrontPlateFitImage.Get();
    FbxBool frontPlateKeepRatio = pCamera->FrontPlateKeepRatio.Get();
    FbxBool lockInterestNavigation = pCamera->LockInterestNavigation.Get();
    FbxBool lockMode = pCamera->LockMode.Get();
    FbxBool showAudio = pCamera->ShowAudio.Get();
    FbxBool showAzimut = pCamera->ShowAzimut.Get();
    FbxBool showBackplate = pCamera->ShowBackplate.Get();
    FbxBool showFrontplate = pCamera->ShowFrontplate.Get();
    FbxBool showGrid = pCamera->ShowGrid.Get();
    FbxBool showInfoOnMoving = pCamera->ShowInfoOnMoving.Get();
    FbxBool showName = pCamera->ShowName.Get();
    FbxBool showOpticalCenter = pCamera->ShowOpticalCenter.Get();
    FbxBool showTimeCode = pCamera->ShowTimeCode.Get();
    FbxBool use2DMagnifierZoom = pCamera->Use2DMagnifierZoom.Get();
    FbxBool useAccumulationBuffer = pCamera->UseAccumulationBuffer.Get();
    FbxBool useAntialiasing = pCamera->UseAntialiasing.Get();
    FbxBool useDepthOfField = pCamera->UseDepthOfField.Get();
    FbxBool useFrameColor = pCamera->UseFrameColor.Get();
    FbxBool useMotionBlur = pCamera->UseMotionBlur.Get();
    FbxBool useRealTimeDOFAndAA = pCamera->UseRealTimeDOFAndAA.Get();
    FbxBool useRealTimeMotionBlur = pCamera->UseRealTimeMotionBlur.Get();
    FbxBool viewCameraToLookAt = pCamera->ViewCameraToLookAt.Get();
    FbxBool viewFrustumNearFarPlane = pCamera->ViewFrustumNearFarPlane.Get();
    FbxDouble antialiasingIntensity = pCamera->AntialiasingIntensity.Get();
    FbxDouble aspectHeight = pCamera->AspectHeight.Get();
    FbxDouble aspectWidth = pCamera->AspectWidth.Get();
    FbxDouble backPlaneDistance = pCamera->BackPlaneDistance.Get();
    FbxDouble backPlaneOffsetX = pCamera->BackPlaneOffsetX.Get();
    FbxDouble backPlaneOffsetY = pCamera->BackPlaneOffsetY.Get();
    FbxDouble backPlaneRotation = pCamera->BackPlaneRotation.Get();
    FbxDouble backPlaneScaleX = pCamera->BackPlaneScaleX.Get();
    FbxDouble backPlaneScaleY = pCamera->BackPlaneScaleY.Get();
    FbxDouble backgroundAlphaTreshold = pCamera->BackgroundAlphaTreshold.Get();
    FbxDouble farPlane = pCamera->FarPlane.Get();
    FbxDouble fieldOfView = pCamera->FieldOfView.Get();
    FbxDouble fieldOfViewX = pCamera->FieldOfViewX.Get();
    FbxDouble fieldOfViewY = pCamera->FieldOfViewY.Get();
    FbxDouble filmAspectRatio = pCamera->FilmAspectRatio.Get();
    FbxDouble filmHeight = pCamera->FilmHeight.Get();
    FbxDouble filmOffsetX = pCamera->FilmOffsetX.Get();
    FbxDouble filmOffsetY = pCamera->FilmOffsetY.Get();
    FbxDouble filmRollPivotX = pCamera->FilmRollPivotX.Get();
    FbxDouble filmRollPivotY = pCamera->FilmRollPivotY.Get();
    FbxDouble filmRollValue = pCamera->FilmRollValue.Get();
    FbxDouble filmSqueezeRatio = pCamera->FilmSqueezeRatio.Get();
    FbxDouble filmTranslateX = pCamera->FilmTranslateX.Get();
    FbxDouble filmTranslateY = pCamera->FilmTranslateY.Get();
    FbxDouble filmWidth = pCamera->FilmWidth.Get();
    FbxDouble focalLength = pCamera->FocalLength.Get();
    FbxDouble focusAngle = pCamera->FocusAngle.Get();
    FbxDouble focusDistance = pCamera->FocusDistance.Get();
    FbxDouble foregroundOpacity = pCamera->ForegroundOpacity.Get();
    FbxDouble frontPlaneDistance = pCamera->FrontPlaneDistance.Get();
    FbxDouble frontPlaneOffsetX = pCamera->FrontPlaneOffsetX.Get();
    FbxDouble frontPlaneOffsetY = pCamera->FrontPlaneOffsetY.Get();
    FbxDouble frontPlaneRotation = pCamera->FrontPlaneRotation.Get();
    FbxDouble frontPlaneScaleX = pCamera->FrontPlaneScaleX.Get();
    FbxDouble frontPlaneScaleY = pCamera->FrontPlaneScaleY.Get();
    FbxDouble motionBlurIntensity = pCamera->MotionBlurIntensity.Get();
    FbxDouble nearPlane = pCamera->NearPlane.Get();
    FbxDouble opticalCenterX = pCamera->OpticalCenterX.Get();
    FbxDouble opticalCenterY = pCamera->OpticalCenterY.Get();
    FbxDouble orthoZoom = pCamera->OrthoZoom.Get();
    FbxDouble pixelAspectRatio = pCamera->PixelAspectRatio.Get();
    FbxDouble preScale = pCamera->PreScale.Get();
    FbxDouble roll = pCamera->Roll.Get();
    FbxDouble safeAreaAspectRatio = pCamera->SafeAreaAspectRatio.Get();
    FbxDouble turnTable = pCamera->TurnTable.Get();
    FbxDouble the2DMagnifierX = pCamera->_2DMagnifierX.Get();
    FbxDouble the2DMagnifierY = pCamera->_2DMagnifierY.Get();
    FbxDouble the2DMagnifierZoom = pCamera->_2DMagnifierZoom.Get();
    FbxDouble3 audioColor = pCamera->AudioColor.Get();
    FbxDouble3 backgroundColor = pCamera->BackgroundColor.Get();
    FbxDouble3 frameColor = pCamera->FrameColor.Get();
    FbxDouble3 interestPosition = pCamera->InterestPosition.Get();
    FbxDouble3 position = pCamera->Position.Get();
    FbxDouble3 upVector = pCamera->UpVector.Get();
    FbxInt frameSamplingCount = pCamera->FrameSamplingCount.Get();

    int antialiasingMethod = CameraEAntialiasingMethodToInt(pCamera->AntialiasingMethod.Get());
    int filmFormat = CameraEApertureFormatToInt(pCamera->FilmFormat.Get());
    int apertureMode = CameraEApertureModeToInt(pCamera->ApertureMode.Get());
    int aspectRatioMode = CameraEAspectRatioModeToInt(pCamera->AspectRatioMode.Get());
    int filmRollOrder = CameraEFilmRollOrderToInt(pCamera->FilmRollOrder.Get());
    int focusSource = CameraEFocusDistanceSourceToInt(pCamera->FocusSource.Get());
    int cameraFormat = CameraEFormatToInt(pCamera->CameraFormat.Get());
    int viewFrustumBackPlaneMode = CameraEFrontBackPlaneDisplayModeToInt(pCamera->ViewFrustumBackPlaneMode.Get());
    int viewFrustumFrontPlaneMode = CameraEFrontBackPlaneDisplayModeToInt(pCamera->ViewFrustumFrontPlaneMode.Get());
    int backPlaneDistanceMode = CameraEFrontBackPlaneDistanceModeToInt(pCamera->BackPlaneDistanceMode.Get());
    int frontPlaneDistanceMode = CameraEFrontBackPlaneDistanceModeToInt(pCamera->FrontPlaneDistanceMode.Get());
    int gateFit = CameraEGateFitToInt(pCamera->GateFit.Get());
    int projectionType = CameraEProjectionTypeToInt(pCamera->ProjectionType.Get());
    int safeAreaDisplayStyle = CameraESafeAreaStyleToInt(pCamera->SafeAreaDisplayStyle.Get());
    int frameSamplingType = CameraESamplingTypeToInt(pCamera->FrameSamplingType.Get());

    // FbxReference backgroundTexture = pCamera->BackgroundTexture.Get();
    // FbxReference foregroundTexture = pCamera->ForegroundTexture.Get();

    bool viewCameraInterest = pCamera->GetViewCameraInterest();
    bool viewNearFarPlanes = pCamera->GetViewNearFarPlanes();
    double apertureHeight = pCamera->GetApertureHeight();
    double apertureWidth = pCamera->GetApertureWidth();
    double pixelRatio = pCamera->GetPixelRatio();
    double squeezeRatio = pCamera->GetSqueezeRatio();

    int apertureFormat = CameraEApertureFormatToInt(pCamera->GetApertureFormat());

    // const char* GetBackgroundFileName();
    // const char* GetBackgroundMediaName();
    // const char* GetForegroundFileName();
    // const char* GetForegroundMediaName();
    // virtual FbxStringList GetTypeFlags();

    return id;
}
//------------------------------------------------------------
// Mesh

static FbxUInt64 meshID = -1;

FbxUInt64 VisitMesh(Exporters* exporters, FbxMesh* pMesh)
{
    // early out check already done in VisitAttribute
    FbxUInt64 id = meshID+=1;
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

    // Polygons
    int polygonCount = pMesh->GetPolygonCount();
    for (int polyIndex = 0; polyIndex < polygonCount; polyIndex++)
    {
        int polyGroup = pMesh->GetPolygonGroup(polyIndex);
        int polySize = pMesh->GetPolygonSize(polyIndex);
        for (int vertIndex = 0; vertIndex < polySize; vertIndex++)
        {
            int index = pMesh->GetPolygonVertex(polyIndex, vertIndex);
        }
    }

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
    case FbxNodeAttribute::eSkeleton: return VisitSkeleton(exporters, (FbxSkeleton*)pAttribute);
    case FbxNodeAttribute::eMesh: return VisitMesh(exporters, (FbxMesh*)pAttribute);
    case FbxNodeAttribute::eNurbs: return -1;
    case FbxNodeAttribute::ePatch: return -1;
    case FbxNodeAttribute::eCamera: return VisitCamera(exporters, (FbxCamera*)pAttribute);
    case FbxNodeAttribute::eCameraStereo: return -1;
    case FbxNodeAttribute::eCameraSwitcher: return -1;
    case FbxNodeAttribute::eLight: return VisitLight(exporters, (FbxLight*)pAttribute);
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
