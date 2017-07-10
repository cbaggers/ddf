#include "include/enumConversion.h"
#include "include/exporters.h"
#include "include/globalSettings.h"

//------------------------------------------------------------
// Global Settings

static bool hasVisited = false;

FbxUInt64 VisitGlobalSettings(Exporters* exporters, FbxGlobalSettings* pSettings)
{
    if (hasVisited) exit(1001);
    hasVisited = true;



    return 0;
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
