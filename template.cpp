#include "include/enumConversion.h"
#include "include/exporters.h"
#include "include/foo.h"

//------------------------------------------------------------
// Foo

static FbxUInt64 fooID = -1;

FbxUInt64 VisitFoo(Exporters* exporters, FbxFoo* pFoo)
{
    if(!pFoo) return -1;
    if (pFoo->GetUserDataPtr()!=NULL) return (FbxUInt64)pFoo->GetUserDataPtr();

    FbxUInt64 id = fooID += 1;
    pFoo->SetUserDataPtr((void*)id);

    return id;
}
