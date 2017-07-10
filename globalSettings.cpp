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



    return id;
}

//------------------------------------------------------------

// int GetCurrentTimeMarker ()
// int GetOriginalUpAxis ()
// int GetTimeMarkerCount ()
// double GetCustomFrameRate ()

// FbxAxisSystem GetAxisSystem ()
// FbxColor GetAmbientColor ()
// FbxString GetDefaultCamera ()
// FbxSystemUnit GetOriginalSystemUnit ()
// FbxSystemUnit GetSystemUnit ()
// TimeMarker GetTimeMarker (int pIndex, FbxStatus *pStatus=NULL)
// void GetTimelineDefaultTimeSpan (FbxTimeSpan &pTimeSpan)

// FbxTime::EMode GetTimeMode ()
// FbxTime::EProtocol GetTimeProtocol ()
// ESnapOnFrameMode GetSnapOnFrameMode ()
