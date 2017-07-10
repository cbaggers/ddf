#include "include/enumConversion.h"
#include "include/exporters.h"
#include "include/character.h"
#include "include/controlSet.h"

//------------------------------------------------------------
// Characters

static FbxUInt64 characterID = -1;

FbxUInt64 VisitCharacter(Exporters* exporters, FbxCharacter* pCharacter)
{
    if (!pCharacter) return -1;
    if (pCharacter->GetUserDataPtr()!=NULL) return (FbxUInt64)pCharacter->GetUserDataPtr();

    FbxUInt64 id = characterID+=1;
    pCharacter->SetUserDataPtr((void*)id);

    FbxCharacter::EInputType inputType = pCharacter->GetInputType();

    FbxUInt64 inputObject = -1;
    FbxObject* pInputObject = pCharacter->GetInputObject();
    if (inputType == FbxCharacter::eInputCharacter)
    {
        FbxCharacter* pInputCharacter = (FbxCharacter*)pInputObject;
        FbxUInt64 inputObject = (FbxUInt64)VisitCharacter(exporters, pInputCharacter);
    }

    FbxControlSet& pControlSet = pCharacter->GetControlSet();
    FbxUInt64 controlSet = VisitControlSet(exporters, &pControlSet);

    FbxBool applyLimits = pCharacter->ApplyLimits.Get();
    FbxBool characterize = pCharacter->Characterize.Get();
    FbxBool fingerSolving = pCharacter->FingerSolving.Get();
    FbxBool footAutomaticToes = pCharacter->FootAutomaticToes.Get();
    FbxBool footFingerContact = pCharacter->FootFingerContact.Get();
    FbxBool footFloorContact = pCharacter->FootFloorContact.Get();
    FbxBool forceActorSpace = pCharacter->ForceActorSpace.Get();
    FbxBool handAutomaticFingers = pCharacter->HandAutomaticFingers.Get();
    FbxBool handFingerContact = pCharacter->HandFingerContact.Get();
    FbxBool handFloorContact = pCharacter->HandFloorContact.Get();
    FbxBool leftArmRollExMode = pCharacter->LeftArmRollExMode.Get();
    FbxBool leftArmRollMode = pCharacter->LeftArmRollMode.Get();
    FbxBool leftElbowKillPitch = pCharacter->LeftElbowKillPitch.Get();
    FbxBool leftForeArmRollExMode = pCharacter->LeftForeArmRollExMode.Get();
    FbxBool leftForeArmRollMode = pCharacter->LeftForeArmRollMode.Get();
    FbxBool leftKneeKillPitch = pCharacter->LeftKneeKillPitch.Get();
    FbxBool leftLegRollExMode = pCharacter->LeftLegRollExMode.Get();
    FbxBool leftLegRollMode = pCharacter->LeftLegRollMode.Get();
    FbxBool leftUpLegRollExMode = pCharacter->LeftUpLegRollExMode.Get();
    FbxBool leftUpLegRollMode = pCharacter->LeftUpLegRollMode.Get();
    FbxBool lockPick = pCharacter->LockPick.Get();
    FbxBool lockXForm = pCharacter->LockXForm.Get();
    FbxBool mirrorMode = pCharacter->MirrorMode.Get();
    FbxBool rightArmRollExMode = pCharacter->RightArmRollExMode.Get();
    FbxBool rightArmRollMode = pCharacter->RightArmRollMode.Get();
    FbxBool rightElbowKillPitch = pCharacter->RightElbowKillPitch.Get();
    FbxBool rightForeArmRollExMode = pCharacter->RightForeArmRollExMode.Get();
    FbxBool rightForeArmRollMode = pCharacter->RightForeArmRollMode.Get();
    FbxBool rightKneeKillPitch = pCharacter->RightKneeKillPitch.Get();
    FbxBool rightLegRollExMode = pCharacter->RightLegRollExMode.Get();
    FbxBool rightLegRollMode = pCharacter->RightLegRollMode.Get();
    FbxBool rightUpLegRollExMode = pCharacter->RightUpLegRollExMode.Get();
    FbxBool rightUpLegRollMode = pCharacter->RightUpLegRollMode.Get();
    FbxBool syncMode = pCharacter->SyncMode.Get();
    FbxBool writeReference = pCharacter->WriteReference.Get();
    FbxDouble ankleDisplacementDamping = pCharacter->AnkleDisplacementDamping.Get();
    FbxDouble ankleHeightCompensation = pCharacter->AnkleHeightCompensation.Get();
    FbxDouble ankleProximityCompensation = pCharacter->AnkleProximityCompensation.Get();
    FbxDouble ankleStabilizationAngularPerimeter = pCharacter->AnkleStabilizationAngularPerimeter.Get();
    FbxDouble ankleStabilizationDamping = pCharacter->AnkleStabilizationDamping.Get();
    FbxDouble ankleStabilizationFloorProximity = pCharacter->AnkleStabilizationFloorProximity.Get();
    FbxDouble ankleStabilizationPerimeter = pCharacter->AnkleStabilizationPerimeter.Get();
    FbxDouble ankleStabilizationRecoveryTime = pCharacter->AnkleStabilizationRecoveryTime.Get();
    FbxDouble ankleStabilizationTime = pCharacter->AnkleStabilizationTime.Get();
    FbxDouble chestReduction = pCharacter->ChestReduction.Get();
    FbxDouble collarReduction = pCharacter->CollarReduction.Get();
    FbxDouble collarStiffnessX = pCharacter->CollarStiffnessX.Get();
    FbxDouble collarStiffnessY = pCharacter->CollarStiffnessY.Get();
    FbxDouble collarStiffnessZ = pCharacter->CollarStiffnessZ.Get();
    FbxDouble ctrlChestPullLeftHand = pCharacter->CtrlChestPullLeftHand.Get();
    FbxDouble ctrlChestPullRightHand = pCharacter->CtrlChestPullRightHand.Get();
    FbxDouble ctrlEnforceGravity = pCharacter->CtrlEnforceGravity.Get();
    FbxDouble ctrlNeckStiffness = pCharacter->CtrlNeckStiffness.Get();
    FbxDouble ctrlPullHead = pCharacter->CtrlPullHead.Get();
    FbxDouble ctrlPullLeftElbow = pCharacter->CtrlPullLeftElbow.Get();
    FbxDouble ctrlPullLeftFingerBase = pCharacter->CtrlPullLeftFingerBase.Get();
    FbxDouble ctrlPullLeftFoot = pCharacter->CtrlPullLeftFoot.Get();
    FbxDouble ctrlPullLeftHand = pCharacter->CtrlPullLeftHand.Get();
    FbxDouble ctrlPullLeftKnee = pCharacter->CtrlPullLeftKnee.Get();
    FbxDouble ctrlPullLeftToeBase = pCharacter->CtrlPullLeftToeBase.Get();
    FbxDouble ctrlPullRightElbow = pCharacter->CtrlPullRightElbow.Get();
    FbxDouble ctrlPullRightFingerBase = pCharacter->CtrlPullRightFingerBase.Get();
    FbxDouble ctrlPullRightFoot = pCharacter->CtrlPullRightFoot.Get();
    FbxDouble ctrlPullRightHand = pCharacter->CtrlPullRightHand.Get();
    FbxDouble ctrlPullRightKnee = pCharacter->CtrlPullRightKnee.Get();
    FbxDouble ctrlPullRightToeBase = pCharacter->CtrlPullRightToeBase.Get();
    FbxDouble ctrlResistChestOrientation = pCharacter->CtrlResistChestOrientation.Get();
    FbxDouble ctrlResistChestPosition = pCharacter->CtrlResistChestPosition.Get();
    FbxDouble ctrlResistCompressionFactorLeftElbow = pCharacter->CtrlResistCompressionFactorLeftElbow.Get();
    FbxDouble ctrlResistCompressionFactorLeftKnee = pCharacter->CtrlResistCompressionFactorLeftKnee.Get();
    FbxDouble ctrlResistCompressionFactorRightElbow = pCharacter->CtrlResistCompressionFactorRightElbow.Get();
    FbxDouble ctrlResistCompressionFactorRightKnee = pCharacter->CtrlResistCompressionFactorRightKnee.Get();
    FbxDouble ctrlResistHipsOrientation = pCharacter->CtrlResistHipsOrientation.Get();
    FbxDouble ctrlResistHipsPosition = pCharacter->CtrlResistHipsPosition.Get();
    FbxDouble ctrlResistLeftCollar = pCharacter->CtrlResistLeftCollar.Get();
    FbxDouble ctrlResistLeftElbow = pCharacter->CtrlResistLeftElbow.Get();
    FbxDouble ctrlResistLeftKnee = pCharacter->CtrlResistLeftKnee.Get();
    FbxDouble ctrlResistMaximumExtensionLeftElbow = pCharacter->CtrlResistMaximumExtensionLeftElbow.Get();
    FbxDouble ctrlResistMaximumExtensionLeftKnee = pCharacter->CtrlResistMaximumExtensionLeftKnee.Get();
    FbxDouble ctrlResistMaximumExtensionRightElbow = pCharacter->CtrlResistMaximumExtensionRightElbow.Get();
    FbxDouble ctrlResistMaximumExtensionRightKnee = pCharacter->CtrlResistMaximumExtensionRightKnee.Get();
    FbxDouble ctrlResistRightCollar = pCharacter->CtrlResistRightCollar.Get();
    FbxDouble ctrlResistRightElbow = pCharacter->CtrlResistRightElbow.Get();
    FbxDouble ctrlResistRightKnee = pCharacter->CtrlResistRightKnee.Get();
    FbxDouble ctrlSpineStiffness = pCharacter->CtrlSpineStiffness.Get();
    FbxDouble damping = pCharacter->Damping.Get();
    FbxDouble displacementDamping = pCharacter->DisplacementDamping.Get();
    FbxDouble displacementMemory = pCharacter->DisplacementMemory.Get();
    FbxDouble extraCollarRatio = pCharacter->ExtraCollarRatio.Get();
    FbxDouble footBackToAnkle = pCharacter->FootBackToAnkle.Get();
    FbxDouble footBottomToAnkle = pCharacter->FootBottomToAnkle.Get();
    FbxDouble footContactSize = pCharacter->FootContactSize.Get();
    FbxDouble footContactStiffness = pCharacter->FootContactStiffness.Get();
    FbxDouble footFingerContactRollStiffness = pCharacter->FootFingerContactRollStiffness.Get();
    FbxDouble footFrontToMiddle = pCharacter->FootFrontToMiddle.Get();
    FbxDouble footInToAnkle = pCharacter->FootInToAnkle.Get();
    FbxDouble footMiddleToAnkle = pCharacter->FootMiddleToAnkle.Get();
    FbxDouble footOutToAnkle = pCharacter->FootOutToAnkle.Get();
    FbxDouble handBackToWrist = pCharacter->HandBackToWrist.Get();
    FbxDouble handBottomToWrist = pCharacter->HandBottomToWrist.Get();
    FbxDouble handContactSize = pCharacter->HandContactSize.Get();
    FbxDouble handContactStiffness = pCharacter->HandContactStiffness.Get();
    FbxDouble handFingerContactRollStiffness = pCharacter->HandFingerContactRollStiffness.Get();
    FbxDouble handFrontToMiddle = pCharacter->HandFrontToMiddle.Get();
    FbxDouble handInToWrist = pCharacter->HandInToWrist.Get();
    FbxDouble handMiddleToWrist = pCharacter->HandMiddleToWrist.Get();
    FbxDouble handOutToWrist = pCharacter->HandOutToWrist.Get();
    FbxDouble headReduction = pCharacter->HeadReduction.Get();
    FbxDouble hikVersion = pCharacter->HikVersion.Get();
    FbxDouble hipsDisplacementDamping = pCharacter->HipsDisplacementDamping.Get();
    FbxDouble hipsHeightCompensation = pCharacter->HipsHeightCompensation.Get();
    FbxDouble leftArmMaxExtensionAngle = pCharacter->LeftArmMaxExtensionAngle.Get();
    FbxDouble leftArmRoll = pCharacter->LeftArmRoll.Get();
    FbxDouble leftArmRollEx = pCharacter->LeftArmRollEx.Get();
    FbxDouble leftFootExtraFingerTip = pCharacter->LeftFootExtraFingerTip.Get();
    FbxDouble leftFootIndexTip = pCharacter->LeftFootIndexTip.Get();
    FbxDouble leftFootMiddleTip = pCharacter->LeftFootMiddleTip.Get();
    FbxDouble leftFootPinkyTip = pCharacter->LeftFootPinkyTip.Get();
    FbxDouble leftFootRingTip = pCharacter->LeftFootRingTip.Get();
    FbxDouble leftFootThumbTip = pCharacter->LeftFootThumbTip.Get();
    FbxDouble leftForeArmRoll = pCharacter->LeftForeArmRoll.Get();
    FbxDouble leftForeArmRollEx = pCharacter->LeftForeArmRollEx.Get();
    FbxDouble leftHandExtraFingerTip = pCharacter->LeftHandExtraFingerTip.Get();
    FbxDouble leftHandIndexTip = pCharacter->LeftHandIndexTip.Get();
    FbxDouble leftHandMiddleTip = pCharacter->LeftHandMiddleTip.Get();
    FbxDouble leftHandPinkyTip = pCharacter->LeftHandPinkyTip.Get();
    FbxDouble leftHandRingTip = pCharacter->LeftHandRingTip.Get();
    FbxDouble leftHandThumbTip = pCharacter->LeftHandThumbTip.Get();
    FbxDouble leftLegMaxExtensionAngle = pCharacter->LeftLegMaxExtensionAngle.Get();
    FbxDouble leftLegRoll = pCharacter->LeftLegRoll.Get();
    FbxDouble leftLegRollEx = pCharacter->LeftLegRollEx.Get();
    FbxDouble leftUpLegRoll = pCharacter->LeftUpLegRoll.Get();
    FbxDouble leftUpLegRollEx = pCharacter->LeftUpLegRollEx.Get();
    FbxDouble massCenterCompensation = pCharacter->MassCenterCompensation.Get();
    FbxDouble neckReduction = pCharacter->NeckReduction.Get();
    FbxDouble orientationDamping = pCharacter->OrientationDamping.Get();
    FbxDouble reachActorChest = pCharacter->ReachActorChest.Get();
    FbxDouble reachActorChestRotation = pCharacter->ReachActorChestRotation.Get();
    FbxDouble reachActorHead = pCharacter->ReachActorHead.Get();
    FbxDouble reachActorHeadRotation = pCharacter->ReachActorHeadRotation.Get();
    FbxDouble reachActorLeftAnkle = pCharacter->ReachActorLeftAnkle.Get();
    FbxDouble reachActorLeftAnkleRotation = pCharacter->ReachActorLeftAnkleRotation.Get();
    FbxDouble reachActorLeftElbow = pCharacter->ReachActorLeftElbow.Get();
    FbxDouble reachActorLeftFingerBase = pCharacter->ReachActorLeftFingerBase.Get();
    FbxDouble reachActorLeftFingerBaseRotation = pCharacter->ReachActorLeftFingerBaseRotation.Get();
    FbxDouble reachActorLeftKnee = pCharacter->ReachActorLeftKnee.Get();
    FbxDouble reachActorLeftToesBase = pCharacter->ReachActorLeftToesBase.Get();
    FbxDouble reachActorLeftToesBaseRotation = pCharacter->ReachActorLeftToesBaseRotation.Get();
    FbxDouble reachActorLeftWrist = pCharacter->ReachActorLeftWrist.Get();
    FbxDouble reachActorLeftWristRotation = pCharacter->ReachActorLeftWristRotation.Get();
    FbxDouble reachActorLowerChestRotation = pCharacter->ReachActorLowerChestRotation.Get();
    FbxDouble reachActorRightAnkle = pCharacter->ReachActorRightAnkle.Get();
    FbxDouble reachActorRightAnkleRotation = pCharacter->ReachActorRightAnkleRotation.Get();
    FbxDouble reachActorRightElbow = pCharacter->ReachActorRightElbow.Get();
    FbxDouble reachActorRightFingerBase = pCharacter->ReachActorRightFingerBase.Get();
    FbxDouble reachActorRightFingerBaseRotation = pCharacter->ReachActorRightFingerBaseRotation.Get();
    FbxDouble reachActorRightKnee = pCharacter->ReachActorRightKnee.Get();
    FbxDouble reachActorRightToesBase = pCharacter->ReachActorRightToesBase.Get();
    FbxDouble reachActorRightToesBaseRotation = pCharacter->ReachActorRightToesBaseRotation.Get();
    FbxDouble reachActorRightWrist = pCharacter->ReachActorRightWrist.Get();
    FbxDouble reachActorRightWristRotation = pCharacter->ReachActorRightWristRotation.Get();
    FbxDouble realisticShoulder = pCharacter->RealisticShoulder.Get();
    FbxDouble rightArmMaxExtensionAngle = pCharacter->RightArmMaxExtensionAngle.Get();
    FbxDouble rightArmRoll = pCharacter->RightArmRoll.Get();
    FbxDouble rightArmRollEx = pCharacter->RightArmRollEx.Get();
    FbxDouble rightFootExtraFingerTip = pCharacter->RightFootExtraFingerTip.Get();
    FbxDouble rightFootIndexTip = pCharacter->RightFootIndexTip.Get();
    FbxDouble rightFootMiddleTip = pCharacter->RightFootMiddleTip.Get();
    FbxDouble rightFootPinkyTip = pCharacter->RightFootPinkyTip.Get();
    FbxDouble rightFootRingTip = pCharacter->RightFootRingTip.Get();
    FbxDouble rightFootThumbTip = pCharacter->RightFootThumbTip.Get();
    FbxDouble rightForeArmExRoll = pCharacter->RightForeArmExRoll.Get();
    FbxDouble rightForeArmRoll = pCharacter->RightForeArmRoll.Get();
    FbxDouble rightHandExtraFingerTip = pCharacter->RightHandExtraFingerTip.Get();
    FbxDouble rightHandIndexTip = pCharacter->RightHandIndexTip.Get();
    FbxDouble rightHandMiddleTip = pCharacter->RightHandMiddleTip.Get();
    FbxDouble rightHandPinkyTip = pCharacter->RightHandPinkyTip.Get();
    FbxDouble rightHandRingTip = pCharacter->RightHandRingTip.Get();
    FbxDouble rightHandThumbTip = pCharacter->RightHandThumbTip.Get();
    FbxDouble rightLegMaxExtensionAngle = pCharacter->RightLegMaxExtensionAngle.Get();
    FbxDouble rightLegRoll = pCharacter->RightLegRoll.Get();
    FbxDouble rightLegRollEx = pCharacter->RightLegRollEx.Get();
    FbxDouble rightUpLegRoll = pCharacter->RightUpLegRoll.Get();
    FbxDouble rightUpLegRollEx = pCharacter->RightUpLegRollEx.Get();
    FbxDouble scaleCompensation = pCharacter->ScaleCompensation.Get();
    FbxDouble shoulderCorrection = pCharacter->ShoulderCorrection.Get();
    FbxDouble snSNeckFreedom = pCharacter->SnSNeckFreedom.Get();
    FbxDouble snSReachChestEnd = pCharacter->SnSReachChestEnd.Get();
    FbxDouble snSReachHead = pCharacter->SnSReachHead.Get();
    FbxDouble snSReachLeftAnkle = pCharacter->SnSReachLeftAnkle.Get();
    FbxDouble snSReachLeftWrist = pCharacter->SnSReachLeftWrist.Get();
    FbxDouble snSReachRightAnkle = pCharacter->SnSReachRightAnkle.Get();
    FbxDouble snSReachRightWrist = pCharacter->SnSReachRightWrist.Get();
    FbxDouble snSScaleArmsAndLegs = pCharacter->SnSScaleArmsAndLegs.Get();
    FbxDouble snSScaleNeck = pCharacter->SnSScaleNeck.Get();
    FbxDouble snSScaleSpine = pCharacter->SnSScaleSpine.Get();
    FbxDouble snSScaleSpineChildren = pCharacter->SnSScaleSpineChildren.Get();
    FbxDouble snSSpineFreedom = pCharacter->SnSSpineFreedom.Get();
    FbxDouble stabilization = pCharacter->Stabilization.Get();
    FbxDouble stretchStartArmsAndLegs = pCharacter->StretchStartArmsAndLegs.Get();
    FbxDouble stretchStopArmsAndLegs = pCharacter->StretchStopArmsAndLegs.Get();
    FbxDouble wristDisplacementDamping = pCharacter->WristDisplacementDamping.Get();
    FbxDouble3 chestTOffset = pCharacter->ChestTOffset.Get();
    FbxDouble3 hipsTOffset = pCharacter->HipsTOffset.Get();
    FbxInt pullIterationCount = pCharacter->PullIterationCount.Get();
    int ankleHeightCompensationMode = EOffAutoUserToInt(pCharacter->AnkleHeightCompensationMode.Get());
    int ankleProximityCompensationMode = EOffAutoUserToInt(pCharacter->AnkleProximityCompensationMode.Get());
    int ankleStabilizationAngularPerimeterMode = EOffAutoUserToInt(pCharacter->AnkleStabilizationAngularPerimeterMode.Get());
    int ankleStabilizationDampingMode = EOffAutoUserToInt(pCharacter->AnkleStabilizationDampingMode.Get());
    int ankleStabilizationFloorProximityMode = EOffAutoUserToInt(pCharacter->AnkleStabilizationFloorProximityMode.Get());
    int ankleStabilizationRecoveryTimeMode = EOffAutoUserToInt(pCharacter->AnkleStabilizationRecoveryTimeMode.Get());
    int displacementDampingMode = EOffAutoUserToInt(pCharacter->DisplacementDampingMode.Get());
    int hipsHeightCompensationMode = EOffAutoUserToInt(pCharacter->HipsHeightCompensationMode.Get());
    int orientationDampingMode = EOffAutoUserToInt(pCharacter->OrientationDampingMode.Get());
    int scaleCompensationMode = EOffAutoUserToInt(pCharacter->ScaleCompensationMode.Get());
    int rollExtractionMode = ERollExtractionModeToInt(pCharacter->RollExtractionMode.Get());
    int posture = EPostureModeToInt(pCharacter->Posture.Get());
    int footFloorPivot = EFloorPivotToInt(pCharacter->FootFloorPivot.Get());
    int handFloorPivot = EFloorPivotToInt(pCharacter->HandFloorPivot.Get());
    int ankleDisplacementDampingMode = EAutoUserToInt(pCharacter->AnkleDisplacementDampingMode.Get());
    int ankleStabilizationPerimeterMode = EAutoUserToInt(pCharacter->AnkleStabilizationPerimeterMode.Get());
    int ankleStabilizationTimeMode = EAutoUserToInt(pCharacter->AnkleStabilizationTimeMode.Get());
    int displacementMemoryMode = EAutoUserToInt(pCharacter->DisplacementMemoryMode.Get());
    int hipsDisplacementDampingMode = EAutoUserToInt(pCharacter->HipsDisplacementDampingMode.Get());
    int wristDisplacementDampingMode = EAutoUserToInt(pCharacter->WristDisplacementDampingMode.Get());
    int hipsTranslationMode = EHipsTranslationModeToInt(pCharacter->HipsTranslationMode.Get());
    int contactBehaviour = EContactBehaviourToInt(pCharacter->ContactBehaviour.Get());
    int footFingerContactMode = EFingerContactModeToInt(pCharacter->FootFingerContactMode.Get());
    int handFingerContactMode = EFingerContactModeToInt(pCharacter->HandFingerContactMode.Get());
    int footContactType = EFootContactTypeToInt(pCharacter->FootContactType.Get());
    int handContactType = EHandContactTypeToInt(pCharacter->HandContactType.Get());

    // FbxReference actor = pCharacter->Actor.Get();
    // FbxReference character = pCharacter->Character.Get();
    // FbxReference controlSet = pCharacter->ControlSet.Get();
    // FbxReference destinationObject = pCharacter->DestinationObject.Get();
    // FbxReference sourceObject = pCharacter->SourceObject.Get();

    return id;
}

//------------------------------------------------------------

// static FbxUInt64 GetCharacterGroupCount (EGroupId pCharacterGroupId)
// static FbxUInt64 GetCharacterGroupVersionByIndex (EGroupId pCharacterGroupId, int pIndex)
// static ENodeId GetCharacterGroupElementByIndex (EGroupId pCharacterGroupId, int pIndex)
// static char * GetCharacterGroupNameByIndex (EGroupId pCharacterGroupId, int pIndex)
