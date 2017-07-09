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
