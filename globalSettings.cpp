#include "include/enumConversion.h"
#include "include/exporters.h"
#include "include/globalSettings.h"

//------------------------------------------------------------
// Global Settings

static int settingsID = -1;

FbxUInt64 VisitGlobalSettings(Exporters* exporters, FbxGlobalSettings* pSettings)
{
    if(!pSettings) return -1;
    if (pSettings->GetUserDataPtr()!=NULL) return (FbxUInt64)pSettings->GetUserDataPtr();

    int id = settingsID += 1;
    pSettings->SetUserDataPtr((void*)id);

    int currentTimeMarker = pSettings->GetCurrentTimeMarker();
    int originalUpAxis = pSettings->GetOriginalUpAxis();
    int timeMarkerCount = pSettings->GetTimeMarkerCount();
    double customFrameRate = pSettings->GetCustomFrameRate();
    FbxColor ambientColor = pSettings->GetAmbientColor();
    FbxString defaultCamera = pSettings->GetDefaultCamera();

    return id;
}

//------------------------------------------------------------

// FbxAxisSystem axisSystem = pSettings->GetAxisSystem();
// FbxSystemUnit originalSystemUnit = pSettings->GetOriginalSystemUnit();
// FbxSystemUnit systemUnit = pSettings->GetSystemUnit();
// TimeMarker timeMarker = pSettings->GetTimeMarker (int pIndex, FbxStatus *pStatus=NULL);
// void timelineDefaultTimeSpan = pSettings->GetTimelineDefaultTimeSpan (FbxTimeSpan &pTimeSpan);
// FbxTime::EMode = pSettings->GetTimeMode();
// FbxTime::EProtocol pSettings->GetTimeProtocol();
// ESnapOnFrameMode snapOnFrameMode = pSettings->GetSnapOnFrameMode();
