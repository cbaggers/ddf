#include "include/enumConversion.h"
#include "include/exporters.h"
#include "include/attribute.h"
#include "include/layer.h"

//------------------------------------------------------------
// Camera

static int cameraID = -1;

FbxUInt64 VisitCamera(Exporters* exporters, FbxCamera* pCamera)
{
    // early out check already done in VisitAttribute
    int id = cameraID+=1;
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

    // EAntialiasingMethod antialiasingMethod = pCamera->AntialiasingMethod.Get();
    // EApertureFormat filmFormat = pCamera->FilmFormat.Get();
    // EApertureMode apertureMode = pCamera->ApertureMode.Get();
    // EAspectRatioMode aspectRatioMode = pCamera->AspectRatioMode.Get();
    // EFilmRollOrder filmRollOrder = pCamera->FilmRollOrder.Get();
    // EFocusDistanceSource focusSource = pCamera->FocusSource.Get();
    // EFormat cameraFormat = pCamera->CameraFormat.Get();
    // EFrontBackPlaneDisplayMode viewFrustumBackPlaneMode = pCamera->ViewFrustumBackPlaneMode.Get();
    // EFrontBackPlaneDisplayMode viewFrustumFrontPlaneMode = pCamera->ViewFrustumFrontPlaneMode.Get();
    // EFrontBackPlaneDistanceMode backPlaneDistanceMode = pCamera->BackPlaneDistanceMode.Get();
    // EFrontBackPlaneDistanceMode frontPlaneDistanceMode = pCamera->FrontPlaneDistanceMode.Get();
    // EGateFit gateFit = pCamera->GateFit.Get();
    // EProjectionType projectionType = pCamera->ProjectionType.Get();
    // ESafeAreaStyle safeAreaDisplayStyle = pCamera->SafeAreaDisplayStyle.Get();
    // ESamplingType frameSamplingType = pCamera->FrameSamplingType.Get();

    // FbxReference backgroundTexture = pCamera->BackgroundTexture.Get();
    // FbxReference foregroundTexture = pCamera->ForegroundTexture.Get();

    return id;
}
//------------------------------------------------------------
// Mesh

static int meshID = -1;

FbxUInt64 VisitMesh(Exporters* exporters, FbxMesh* pMesh)
{
    // early out check already done in VisitAttribute
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
    case FbxNodeAttribute::eSkeleton: return -1;
    case FbxNodeAttribute::eMesh: return VisitMesh(exporters, (FbxMesh*)pAttribute);
    case FbxNodeAttribute::eNurbs: return -1;
    case FbxNodeAttribute::ePatch: return -1;
    case FbxNodeAttribute::eCamera: return VisitCamera(exporters, (FbxCamera*)pAttribute);
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
