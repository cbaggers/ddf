#include "include/enumConversion.h"
#include "include/exporters.h"
#include "include/surfacematerial.h"

static int surfaceMaterialID = 0;

//------------------------------------------------------------
// Surface Materials

FbxUInt64 VisitSurfaceMaterial(Exporters* exporters, FbxSurfaceMaterial* pMaterial)
{
    if(!pMaterial) return false;
}

//------------------------------------------------------------
