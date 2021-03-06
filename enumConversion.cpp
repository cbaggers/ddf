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

int ERollExtractionModeToInt(FbxCharacter::ERollExtractionMode mode)
{
    switch (mode)
    {
    case FbxCharacter::eRelativeRollExtraction: return 0;
    case FbxCharacter::eAbsoluteRollExtraction: return 1;
    case FbxCharacter::eRollExtractionTypeCount: return 2;
    }
    exit(6);
}

int EPostureModeToInt(FbxCharacter::EPostureMode mode)
{
    switch (mode)
    {
    case FbxCharacter::ePostureBiped: return 0;
    case FbxCharacter::ePostureQuadriped: return 1;
    case FbxCharacter::ePostureCount: return 2;
    }
    exit(7);
}

int EOffAutoUserToInt(FbxCharacter::EOffAutoUser user)
{
    switch (user)
    {
    case FbxCharacter::eParamModeOff: return 0;
    case FbxCharacter::eParamModeAuto: return 1;
    case FbxCharacter::eParamModeUser: return 2;
    }
    exit(8);
}

int EAutoUserToInt(FbxCharacter::EAutoUser user)
{
    switch (user)
    {
    case FbxCharacter::eParamModeAuto2: return 0;
    case FbxCharacter::eParamModeUser2: return 1;
    }
    exit(9);
}

int EFloorPivotToInt(FbxCharacter::EFloorPivot pivot)
{
    switch (pivot)
    {
    case FbxCharacter::eFloorPivotAuto: return 0;
    case FbxCharacter::eFloorPivotAnkle: return 1;
    case FbxCharacter::eFloorPivotToes: return 2;
    case FbxCharacter::eFloorPivotCount: return 3;
    }
    exit(11);
}

int EHipsTranslationModeToInt(FbxCharacter::EHipsTranslationMode mode)
{
    switch (mode)
    {
    case FbxCharacter::eHipsTranslationWorldRigid: return 0;
    case FbxCharacter::eHipsTranslationBodyRigid: return 1;
    case FbxCharacter::eHipsTranslationTypeCount: return 2;
    }
    exit(13);
}


int EFootContactTypeToInt(FbxCharacter::EFootContactType mode)
{
    switch (mode)
    {
    case FbxCharacter::eFootTypeNormal: return 0;
    case FbxCharacter::eFootTypeAnkle: return 1;
    case FbxCharacter::eFootTypeToeBase: return 2;
    case FbxCharacter::eFootTypeHoof: return 3;
    case FbxCharacter::eFootContactModeCount: return 4;
    }
    exit(14);
}

int EHandContactTypeToInt(FbxCharacter::EHandContactType mode)
{
    switch (mode)
    {
    case FbxCharacter::eHandTypeNormal: return 0;
    case FbxCharacter::eHandTypeWrist: return 1;
    case FbxCharacter::eHandTypeFingerBase: return 2;
    case FbxCharacter::eHandTypeHoof: return 3;
    case FbxCharacter::eHandContactModeCount: return 4;
    }
    exit(15);
}

int EFingerContactModeToInt(FbxCharacter::EFingerContactMode mode)
{
    switch (mode)
    {
    case FbxCharacter::eFingerContactModeSticky: return 0;
    case FbxCharacter::eFingerContactModeSpread: return 1;
    case FbxCharacter::eFingerContactModeStickySpread: return 2;
    case FbxCharacter::eFingerContactModeCount: return 3;
    }
    exit(16);
}

int EContactBehaviourToInt(FbxCharacter::EContactBehaviour mode)
{
    switch (mode)
    {
    case FbxCharacter::eContactNeverSync: return 0;
    case FbxCharacter::eContactSyncOnKey: return 1;
    case FbxCharacter::eContactAlwaysSync: return 2;
    case FbxCharacter::eContactBehaviorCount: return 3;
    }
    exit(17);
}

int NodeAttributeETypeToInt(FbxNodeAttribute::EType attrType)
{
    switch (attrType)
    {
    case FbxNodeAttribute::eUnknown: return 0;
    case FbxNodeAttribute::eNull: return 1;
    case FbxNodeAttribute::eMarker: return 2;
    case FbxNodeAttribute::eSkeleton: return 3;
    case FbxNodeAttribute::eMesh: return 4;
    case FbxNodeAttribute::eNurbs: return 5;
    case FbxNodeAttribute::ePatch: return 6;
    case FbxNodeAttribute::eCamera: return 7;
    case FbxNodeAttribute::eCameraStereo: return 8;
    case FbxNodeAttribute::eCameraSwitcher: return 9;
    case FbxNodeAttribute::eLight: return 10;
    case FbxNodeAttribute::eOpticalReference: return 11;
    case FbxNodeAttribute::eOpticalMarker: return 12;
    case FbxNodeAttribute::eNurbsCurve: return 13;
    case FbxNodeAttribute::eTrimNurbsSurface: return 14;
    case FbxNodeAttribute::eBoundary: return 15;
    case FbxNodeAttribute::eNurbsSurface: return 16;
    case FbxNodeAttribute::eShape: return 17;
    case FbxNodeAttribute::eLODGroup: return 18;
    case FbxNodeAttribute::eSubDiv: return 19;
    case FbxNodeAttribute::eCachedEffect: return 20;
    case FbxNodeAttribute::eLine: return 21;
    }
    exit(18);
}

int LayerElementETypeToInt(FbxLayerElement::EType attrType)
{
    switch (attrType)
    {
    case FbxLayerElement::eUnknown: return 0;
    case FbxLayerElement::eNormal: return 1;
    case FbxLayerElement::eBiNormal: return 2;
    case FbxLayerElement::eTangent: return 3;
    case FbxLayerElement::eMaterial: return 4;
    case FbxLayerElement::ePolygonGroup: return 5;
    case FbxLayerElement::eUV: return 6;
    case FbxLayerElement::eVertexColor: return 7;
    case FbxLayerElement::eSmoothing: return 8;
    case FbxLayerElement::eVertexCrease: return 9;
    case FbxLayerElement::eEdgeCrease: return 10;
    case FbxLayerElement::eHole: return 11;
    case FbxLayerElement::eUserData: return 12;
    case FbxLayerElement::eVisibility: return 13;
    case FbxLayerElement::eTextureDiffuse: return 14;
    case FbxLayerElement::eTextureDiffuseFactor: return 15;
    case FbxLayerElement::eTextureEmissive: return 16;
    case FbxLayerElement::eTextureEmissiveFactor: return 17;
    case FbxLayerElement::eTextureAmbient: return 18;
    case FbxLayerElement::eTextureAmbientFactor: return 19;
    case FbxLayerElement::eTextureSpecular: return 20;
    case FbxLayerElement::eTextureSpecularFactor: return 21;
    case FbxLayerElement::eTextureShininess: return 22;
    case FbxLayerElement::eTextureNormalMap: return 23;
    case FbxLayerElement::eTextureBump: return 24;
    case FbxLayerElement::eTextureTransparency: return 25;
    case FbxLayerElement::eTextureTransparencyFactor: return 26;
    case FbxLayerElement::eTextureReflection: return 27;
    case FbxLayerElement::eTextureReflectionFactor: return 28;
    case FbxLayerElement::eTextureDisplacement: return 29;
    case FbxLayerElement::eTextureDisplacementVector: return 30;
    case FbxLayerElement::eTypeCount: return 31;
    }
    exit(19);
}

int LayerElementMappingModeToInt(FbxLayerElement::EMappingMode mode)
{
    switch (mode)
    {
    case FbxLayerElement::eNone: return 0;
    case FbxLayerElement::eByControlPoint: return 1;
    case FbxLayerElement::eByPolygonVertex: return 2;
    case FbxLayerElement::eByPolygon: return 3;
    case FbxLayerElement::eByEdge: return 4;
    case FbxLayerElement::eAllSame: return 5;
    }
    exit(20);
}

int LayerElementReferenceModeToInt(FbxLayerElement::EReferenceMode mode)
{
    switch (mode)
    {
    case FbxLayerElement::eDirect: return 0;
    // In FBX V>=6, eIndex is replaced with eIndexToDirect.
    case FbxLayerElement::eIndex: return 1;
    case FbxLayerElement::eIndexToDirect: return 1;
    }
    exit(21);
}

int CameraEProjectionTypeToInt(FbxCamera::EProjectionType mode)
{
    switch (mode)
    {
    case FbxCamera::ePerspective: return 0;
    case FbxCamera::eOrthogonal: return 1;
    }
    exit(22);
}


int CameraEFormatToInt(FbxCamera::EFormat mode)
{
    switch (mode)
    {
    case FbxCamera::eCustomFormat: return 0;
    case FbxCamera::eD1NTSC: return 1;
    case FbxCamera::eNTSC: return 2;
    case FbxCamera::ePAL: return 3;
    case FbxCamera::eD1PAL: return 4;
    case FbxCamera::eHD: return 5;
    case FbxCamera::e640x480: return 6;
    case FbxCamera::e320x200: return 7;
    case FbxCamera::e320x240: return 8;
    case FbxCamera::e128x128: return 9;
    case FbxCamera::eFullscreen: return 10;
    }
    exit(23);
};

int CameraEAspectRatioModeToInt(FbxCamera::EAspectRatioMode mode)
{
    switch (mode)
    {
    case FbxCamera::eWindowSize: return 0;
    case FbxCamera::eFixedRatio: return 1;
    case FbxCamera::eFixedResolution: return 2;
    case FbxCamera::eFixedWidth: return 3;
    case FbxCamera::eFixedHeight: return 4;
    }
    exit(24);
};

int CameraEApertureFormatToInt(FbxCamera::EApertureFormat mode)
{
    switch (mode)
    {
    case FbxCamera::eCustomAperture: return 0;
    case FbxCamera::e16mmTheatrical: return 1;
    case FbxCamera::eSuper16mm: return 2;
    case FbxCamera::e35mmAcademy: return 3;
    case FbxCamera::e35mmTVProjection: return 4;
    case FbxCamera::e35mmFullAperture: return 5;
    case FbxCamera::e35mm185Projection: return 6;
    case FbxCamera::e35mmAnamorphic: return 7;
    case FbxCamera::e70mmProjection: return 8;
    case FbxCamera::eVistaVision: return 9;
    case FbxCamera::eDynaVision: return 10;
    case FbxCamera::eIMAX: return 11;
    }
    exit(25);
};

int CameraEApertureModeToInt(FbxCamera::EApertureMode mode)
{
    switch (mode)
    {
    case FbxCamera::eHorizAndVert: return 0;
    case FbxCamera::eHorizontal: return 1;
    case FbxCamera::eVertical: return 2;
    case FbxCamera::eFocalLength: return 3;
    }
    exit(26);
};

int CameraEGateFitToInt(FbxCamera::EGateFit mode)
{
    switch (mode)
    {
    case FbxCamera::eFitNone: return 0;
    case FbxCamera::eFitVertical: return 1;
    case FbxCamera::eFitHorizontal: return 2;
    case FbxCamera::eFitFill: return 3;
    case FbxCamera::eFitOverscan: return 4;
    case FbxCamera::eFitStretch: return 5;
    }
    exit(27);
};

int CameraEFilmRollOrderToInt(FbxCamera::EFilmRollOrder mode)
{
    switch (mode)
    {
    case FbxCamera::eRotateFirst: return 0;
    case FbxCamera::eTranslateFirst: return 1;
    }
    exit(28);
};


int CameraEPlateDrawingModeToInt(FbxCamera::EPlateDrawingMode mode)
{
    switch (mode)
    {
    case FbxCamera::ePlateBackground: return 0;
    case FbxCamera::ePlateForeground: return 1;
    case FbxCamera::ePlateBackAndFront: return 2;
    }
    exit(29);
};


int CameraEFrontBackPlaneDistanceModeToInt(FbxCamera::EFrontBackPlaneDistanceMode mode)
{
    switch (mode)
    {
    case FbxCamera::eRelativeToInterest: return 0;
    case FbxCamera::eRelativeToCamera: return 1;
    }
    exit(30);
};

int CameraEFrontBackPlaneDisplayModeToInt(FbxCamera::EFrontBackPlaneDisplayMode mode)
{
    switch (mode)
    {
    case FbxCamera::ePlanesDisabled: return 0;
    case FbxCamera::ePlanesAlways: return 1;
    case FbxCamera::ePlanesWhenMedia: return 2;
    }
    exit(31);
};

int CameraESafeAreaStyleToInt(FbxCamera::ESafeAreaStyle mode)
{
    switch (mode)
    {
    case FbxCamera::eSafeAreaRound: return 0;
    case FbxCamera::eSafeAreaSquare: return 1;
    }
    exit(32);
};

int CameraERenderOptionsUsageTimeToInt(FbxCamera::ERenderOptionsUsageTime mode)
{
    switch (mode)
    {
    case FbxCamera::eInteractive: return 0;
    case FbxCamera::eOnDemand: return 1;
    }
    exit(33);
};

int CameraEAntialiasingMethodToInt(FbxCamera::EAntialiasingMethod mode)
{
    switch (mode)
    {
    case FbxCamera::eAAOversampling: return 0;
    case FbxCamera::eAAHardware: return 1;
    }
    exit(34);
};

int CameraESamplingTypeToInt(FbxCamera::ESamplingType mode)
{
    switch (mode)
    {
    case FbxCamera::eSamplingUniform: return 0;
    case FbxCamera::eSamplingStochastic: return 1;
    }
    exit(35);
};

int CameraEFocusDistanceSourceToInt(FbxCamera::EFocusDistanceSource mode)
{
    switch (mode)
    {
    case FbxCamera::eFocusSrcCameraInterest: return 0;
    case FbxCamera::eFocusSpecificDistance: return 1;
    }
    exit(36);
};


int LightETypeToInt(FbxLight::EType mode)
{
    switch (mode)
    {
    case FbxLight::ePoint: return 0;
    case FbxLight::eDirectional: return 1;
    case FbxLight::eSpot: return 2;
    case FbxLight::eArea: return 3;
    case FbxLight::eVolume: return 4;
    }
    exit(37);
}

int LightEDecayTypeToInt(FbxLight::EDecayType mode)
{
    switch (mode)
    {
    case FbxLight::eNone: return 0;
    case FbxLight::eLinear: return 1;
    case FbxLight::eQuadratic: return 2;
    case FbxLight::eCubic: return 3;
    }
    exit(38);
}

int LightEAreaLightShapeToInt(FbxLight::EAreaLightShape mode)
{
    switch (mode)
    {
    case FbxLight::eRectangle: return 0;
    case FbxLight::eSphere: return 1;
    }
    exit(39);
}

int SkeletonEtypeToInt(FbxSkeleton::EType mode)
{
    switch (mode)
    {
    case FbxSkeleton::eRoot: return 0;
    case FbxSkeleton::eLimb: return 1;
    case FbxSkeleton::eLimbNode: return 2;
    case FbxSkeleton::eEffector: return 3;
    }
    exit(40);
}

int TextureEUnifiedMappingTypeToInt(FbxTexture::EUnifiedMappingType mode)
{
    switch (mode)
    {
    case FbxTexture::eUMT_UV: return 0;
    case FbxTexture::eUMT_XY: return 1;
    case FbxTexture::eUMT_YZ: return 2;
    case FbxTexture::eUMT_XZ: return 3;
    case FbxTexture::eUMT_SPHERICAL: return 4;
    case FbxTexture::eUMT_CYLINDRICAL: return 5;
    case FbxTexture::eUMT_ENVIRONMENT: return 6;
    case FbxTexture::eUMT_PROJECTION: return 7;
    case FbxTexture::eUMT_BOX: return 8;
    case FbxTexture::eUMT_FACE: return 9;
    case FbxTexture::eUMT_NO_MAPPING: return 10;
    }
    exit(41);
}

int TextureETextureUse6ToInt(FbxTexture::ETextureUse6 mode)
{
    switch (mode)
    {
    case FbxTexture::eTEXTURE_USE_6_STANDARD: return 0;
    case FbxTexture::eTEXTURE_USE_6_SPHERICAL_REFLEXION_MAP: return 1;
    case FbxTexture::eTEXTURE_USE_6_SPHERE_REFLEXION_MAP: return 2;
    case FbxTexture::eTEXTURE_USE_6_SHADOW_MAP: return 3;
    case FbxTexture::eTEXTURE_USE_6_LIGHT_MAP: return 4;
    case FbxTexture::eTEXTURE_USE_6_BUMP_NORMAL_MAP: return 5;
    }
    exit(42);
}

int TextureEWrapModeToInt(FbxTexture::EWrapMode mode)
{
    switch (mode)
    {
    case FbxTexture::eRepeat: return 0;
    case FbxTexture::eClamp: return 1;
    }
    exit(43);
}

int TextureEBlendModeToInt(FbxTexture::EBlendMode mode)
{
    switch (mode)
    {
    case FbxTexture::eTranslucent: return 0;
    case FbxTexture::eAdditive: return 1;
    case FbxTexture::eModulate: return 2;
    case FbxTexture::eModulate2: return 3;
    case FbxTexture::eOver: return 4;
    }
    exit(44);
}

int TextureEAlignModeToInt(FbxTexture::EAlignMode mode)
{
    switch (mode)
    {
    case FbxTexture::eLeft: return 0;
    case FbxTexture::eRight: return 1;
    case FbxTexture::eTop: return 2;
    case FbxTexture::eBottom: return 3;
    }
    exit(45);
}

int TextureECoordinatesToInt(FbxTexture::ECoordinates mode)
{
    switch (mode)
    {
    case FbxTexture::eU: return 0;
    case FbxTexture::eV: return 1;
    case FbxTexture::eW: return 2;
    }
    exit(46);
}

int TextureEAlphaSourceToInt(FbxTexture::EAlphaSource mode)
{
    switch (mode)
    {
    case FbxTexture::eNone: return 0;
    case FbxTexture::eRGBIntensity: return 1;
    case FbxTexture::eBlack: return 2;
    }
    exit(47);
}

int TextureEMappingTypeToInt(FbxTexture::EMappingType mode)
{
    switch (mode)
    {
    case FbxTexture::eNull: return 0;
    case FbxTexture::ePlanar: return 1;
    case FbxTexture::eSpherical: return 2;
    case FbxTexture::eCylindrical: return 3;
    case FbxTexture::eBox: return 4;
    case FbxTexture::eFace: return 5;
    case FbxTexture::eUV: return 6;
    case FbxTexture::eEnvironment: return 7;
    }
    exit(48);
}

int TextureEPlanarMappingNormalToInt(FbxTexture::EPlanarMappingNormal mode)
{
    switch (mode)
    {
    case FbxTexture::ePlanarNormalX: return 0;
    case FbxTexture::ePlanarNormalY: return 1;
    case FbxTexture::ePlanarNormalZ: return 2;
    }
    exit(49);
}

int TextureETextureUseToInt(FbxTexture::ETextureUse mode)
{
    switch (mode)
    {
    case FbxTexture::eStandard: return 0;
    case FbxTexture::eShadowMap: return 1;
    case FbxTexture::eLightMap: return 2;
    case FbxTexture::eSphericalReflectionMap: return 3;
    case FbxTexture::eSphereReflectionMap: return 4;
    case FbxTexture::eBumpNormalMap: return 5;
    }
    exit(50);
}

int LayeredTextureEBlendModeToInt(FbxLayeredTexture::EBlendMode mode)
{
    switch (mode)
    {
    case FbxLayeredTexture::eTranslucent: return 0;
    case FbxLayeredTexture::eAdditive: return 1;
    case FbxLayeredTexture::eModulate: return 2;
    case FbxLayeredTexture::eModulate2: return 3;
    case FbxLayeredTexture::eOver: return 4;
    case FbxLayeredTexture::eNormal: return 5;
    case FbxLayeredTexture::eDissolve: return 6;
    case FbxLayeredTexture::eDarken: return 7;
    case FbxLayeredTexture::eColorBurn: return 8;
    case FbxLayeredTexture::eLinearBurn: return 9;
    case FbxLayeredTexture::eDarkerColor: return 10;
    case FbxLayeredTexture::eLighten: return 11;
    case FbxLayeredTexture::eScreen: return 12;
    case FbxLayeredTexture::eColorDodge: return 13;
    case FbxLayeredTexture::eLinearDodge: return 14;
    case FbxLayeredTexture::eLighterColor: return 15;
    case FbxLayeredTexture::eSoftLight: return 16;
    case FbxLayeredTexture::eHardLight: return 17;
    case FbxLayeredTexture::eVividLight: return 18;
    case FbxLayeredTexture::eLinearLight: return 19;
    case FbxLayeredTexture::ePinLight: return 20;
    case FbxLayeredTexture::eHardMix: return 21;
    case FbxLayeredTexture::eDifference: return 22;
    case FbxLayeredTexture::eExclusion: return 23;
    case FbxLayeredTexture::eSubtract: return 24;
    case FbxLayeredTexture::eDivide: return 25;
    case FbxLayeredTexture::eHue: return 26;
    case FbxLayeredTexture::eSaturation: return 27;
    case FbxLayeredTexture::eColor: return 28;
    case FbxLayeredTexture::eLuminosity: return 29;
    case FbxLayeredTexture::eOverlay: return 30;
    case FbxLayeredTexture::eBlendModeCount: return 31;
    }
    exit(51);
}

int FileTextureEMaterialUseToInt(FbxFileTexture::EMaterialUse mode)
{
    switch (mode)
    {
    case FbxFileTexture::eModelMaterial: return 0;
    case FbxFileTexture::eDefaultMaterial: return 1;
    }
    exit(52);
}



int FbxAnimLayerEBlendModeToInt(FbxAnimLayer::EBlendMode mode)
{
    switch (mode)
    {
    case FbxAnimLayer::eBlendAdditive: return 0;
    case FbxAnimLayer::eBlendOverride: return 1;
    case FbxAnimLayer::eBlendOverridePassthrough : return 2;
    }
    exit(53);
}

int FbxAnimLayerERotationAccumulationModeToInt(FbxAnimLayer::ERotationAccumulationMode  mode)
{
    switch (mode)
    {
    case FbxAnimLayer::eRotationByLayer: return 0;
    case FbxAnimLayer::eRotationByChannel : return 1;
    }
    exit(54);
}

int FbxAnimLayerEScaleAccumulationModeToInt(FbxAnimLayer::EScaleAccumulationMode  mode)
{
    switch (mode)
    {
    case FbxAnimLayer::eScaleMultiply: return 0;
    case FbxAnimLayer::eScaleAdditive : return 1;
    }
    exit(55);
}

int EFbxTypeToInt(EFbxType mode)
{
    switch (mode)
    {
    case eFbxUndefined: return 0;
    case eFbxChar: return 1;
    case eFbxUChar: return 2;
    case eFbxShort: return 3;
    case eFbxUShort: return 4;
    case eFbxUInt: return 5;
    case eFbxLongLong: return 6;
    case eFbxULongLong: return 7;
    case eFbxHalfFloat: return 8;
    case eFbxBool: return 9;
    case eFbxInt: return 10;
    case eFbxFloat: return 11;
    case eFbxDouble: return 12;
    case eFbxDouble2: return 13;
    case eFbxDouble3: return 14;
    case eFbxDouble4: return 15;
    case eFbxDouble4x4: return 16;
    case eFbxEnum: return 17;
    case eFbxString: return 18;
    case eFbxTime: return 19;
    case eFbxReference: return 20;
    case eFbxBlob: return 21;
    case eFbxDistance: return 22;
    case eFbxDateTime: return 23;
    case eFbxTypeCount: return 24;
    case eFbxEnumM: return 25;
    }
    exit(56);
}

int FbxAnimCurveDefETangentModeToInt(FbxAnimCurveDef::ETangentMode mode)
{
    switch (mode)
    {
    case FbxAnimCurveDef::eTangentAuto: return 1;
    case FbxAnimCurveDef::eTangentTCB: return 2;
    case FbxAnimCurveDef::eTangentUser: return 4;
    case FbxAnimCurveDef::eTangentGenericBreak: return 8;
    case FbxAnimCurveDef::eTangentBreak: return 12; // eTangentGenericBreak|eTangentUser
    case FbxAnimCurveDef::eTangentAutoBreak: return 9; // eTangentGenericBreak|eTangentAuto
    case FbxAnimCurveDef::eTangentGenericClamp: return 16;
    case FbxAnimCurveDef::eTangentGenericTimeIndependent: return 32;
    case FbxAnimCurveDef::eTangentGenericClampProgressive: return 96; // 64|eTangentGenericTimeIndependent;
    }
    exit(57);
}

int FbxAnimCurveDefEInterpolationTypeToInt(FbxAnimCurveDef::EInterpolationType mode)
{
    switch (mode)
    {
    case FbxAnimCurveDef::eInterpolationConstant: return 0;
    case FbxAnimCurveDef::eInterpolationLinear: return 1;
    case FbxAnimCurveDef::eInterpolationCubic: return 2;
    }
    exit(58);
}

int FbxAnimCurveDefEWeightedModeToInt(FbxAnimCurveDef::EWeightedMode mode)
{
    switch (mode)
    {
    case FbxAnimCurveDef::eWeightedNone: return 0;
    case FbxAnimCurveDef::eWeightedRight: return 1;
    case FbxAnimCurveDef::eWeightedNextLeft: return 2;
    case FbxAnimCurveDef::eWeightedAll: return 3; // eWeightedRight|eWeightedNextLeft;
    }
    exit(59);
}

int FbxAnimCurveDefEConstantModeToInt(FbxAnimCurveDef::EConstantMode mode)
{
    switch (mode)
    {
    case FbxAnimCurveDef::eConstantStandard: return 0;
    case FbxAnimCurveDef::eConstantNext: return 1;
    }
    exit(60);
}

int FbxAnimCurveDefEVelocityModeToInt(FbxAnimCurveDef::EVelocityMode mode)
{
    switch (mode)
    {
    case FbxAnimCurveDef::eVelocityNone: return 0;
    case FbxAnimCurveDef::eVelocityRight: return 1;
    case FbxAnimCurveDef::eVelocityNextLeft: return 2;
    case FbxAnimCurveDef::eVelocityAll: return 3; // eVelocityRight|eVelocityNextLeft
    }
    exit(61);
}

int FbxAnimCurveDefETangentVisibilityToInt(FbxAnimCurveDef::ETangentVisibility mode)
{
    switch (mode)
    {
    case FbxAnimCurveDef::eTangentShowNone: return 0;
    case FbxAnimCurveDef::eTangentShowLeft: return 1;
    case FbxAnimCurveDef::eTangentShowRight: return 2;
    case FbxAnimCurveDef::eTangentShowBoth: return 3; // eTangentShowLeft|eTangentShowRight
    }
    exit(62);
}

int FbxAnimCurveDefEDataIndexToInt(FbxAnimCurveDef::EDataIndex mode)
{
    switch (mode)
    {
    case FbxAnimCurveDef::eRightSlope: return 0; // also eTCBTension
    case FbxAnimCurveDef::eRightWeight: return 2; // also eTCBBias & eWeights
    case FbxAnimCurveDef::eRightVelocity: return 4; // also eVelocity
    case FbxAnimCurveDef::eNextLeftSlope: return 1; // also eTCBContinuity
    case FbxAnimCurveDef::eNextLeftWeight: return 3;
    case FbxAnimCurveDef::eNextLeftVelocity: return 5;
    }
    exit(63);
}
