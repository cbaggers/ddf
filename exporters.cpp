#include "include/exporters.h"

Buffer* MakeBuffer()
{
    Buffer* buff = new Buffer();
    buff->Size = 1024 * 1024;
    buff->Data = (FbxUInt8*)malloc(buff->Size);
    buff->Pos = 0;
    return buff;
}

NodeExporter* InitExporter(FbxString* path)
{
    NodeExporter* ne = new NodeExporter();
    ne->Buff = MakeBuffer();
    ne->FileStream.open(path.Buffer(), ios::out | ios::binary);
    return ne;
}

Exporters* InitExporters(FbxString* path)
{
    Exporters* r = new Exporters();
    r->FbxBoolExporter = InitExporter(path);
    r->FbxCharExporter = InitExporter(path);
    r->FbxDoubleExporter = InitExporter(path);
    r->FbxFloatExporter = InitExporter(path);
    r->FbxHalfFloatExporter = InitExporter(path);
    r->FbxInt16Exporter = InitExporter(path);
    r->FbxInt32Exporter = InitExporter(path);
    r->FbxInt64Exporter = InitExporter(path);
    r->FbxInt8Exporter = InitExporter(path);
    r->FbxIntExporter = InitExporter(path);
    r->FbxLongExporter = InitExporter(path);
    r->FbxLongLongExporter = InitExporter(path);
    r->FbxShortExporter = InitExporter(path);
    r->FbxUCharExporter = InitExporter(path);
    r->FbxUInt16Exporter = InitExporter(path);
    r->FbxUInt32Exporter = InitExporter(path);
    r->FbxUInt64Exporter = InitExporter(path);
    r->FbxUInt8Exporter = InitExporter(path);
    r->FbxUIntExporter = InitExporter(path);
    r->FbxULongExporter = InitExporter(path);
    r->FbxULongLongExporter = InitExporter(path);
    r->FbxUShortExporter = InitExporter(path);
    return r;
}

void ExportRaw(NodeExporter* exporter, void* ptr, FbxUInt32 byteSize)
{
    Buffer* buff = exporter->Buff;
    FbxUInt32 newPos = buff->Pos + byteSize;
    if (newPos < buff->Size)
    {
        memcpy(ptr, buff->Data + buff->Pos, byteSize);
        buff->Pos = newPos;
    }
    else
    {
        exporter->FileStream.write(buff->Data, buff->Pos);
        memcpy(ptr, buff->Data, byteSize);
        buff->Pos = byteSize;
    }
}

void FlushExporter(NodeExporter* exporter)
{
    exporter->FileStream.write(buff->Data, buff->Pos);
    buff->Pos = 0;
}

void FlushExporters(Exporters* exporters)
{
    Exporters* r = new Exporters();
    FlushExporter(exporters->FbxBoolExporter);
    FlushExporter(exporters->FbxCharExporter);
    FlushExporter(exporters->FbxDoubleExporter);
    FlushExporter(exporters->FbxFloatExporter);
    FlushExporter(exporters->FbxHalfFloatExporter);
    FlushExporter(exporters->FbxInt16Exporter);
    FlushExporter(exporters->FbxInt32Exporter);
    FlushExporter(exporters->FbxInt64Exporter);
    FlushExporter(exporters->FbxInt8Exporter);
    FlushExporter(exporters->FbxIntExporter);
    FlushExporter(exporters->FbxLongExporter);
    FlushExporter(exporters->FbxLongLongExporter);
    FlushExporter(exporters->FbxShortExporter);
    FlushExporter(exporters->FbxUCharExporter);
    FlushExporter(exporters->FbxUInt16Exporter);
    FlushExporter(exporters->FbxUInt32Exporter);
    FlushExporter(exporters->FbxUInt64Exporter);
    FlushExporter(exporters->FbxUInt8Exporter);
    FlushExporter(exporters->FbxUIntExporter);
    FlushExporter(exporters->FbxULongExporter);
    FlushExporter(exporters->FbxULongLongExporter);
    FlushExporter(exporters->FbxUShortExporter);
}

void Export(Exporters* exporters, FbxChar val)
{
    ExportRaw(exporters->FbxCharExporter, &val, sizeof(FbxChar));
}

void Export(Exporters* exporters, FbxUChar val)
{
    ExportRaw(exporters->FbxUCharExporter, &val, sizeof(FbxUChar));
}

void Export(Exporters* exporters, FbxShort val)
{
    ExportRaw(exporters->FbxShortExporter, &val, sizeof(FbxShort));
}

void Export(Exporters* exporters, FbxUShort val)
{
    ExportRaw(exporters->FbxUShortExporter, &val, sizeof(FbxUShort));
}

void Export(Exporters* exporters, FbxUInt val)
{
    ExportRaw(exporters->FbxUIntExporter, &val, sizeof(FbxUInt));
}

void Export(Exporters* exporters, FbxLongLong val)
{
    ExportRaw(exporters->FbxLongLongExporter, &val, sizeof(FbxLongLong));
}

void Export(Exporters* exporters, FbxULongLong val)
{
    ExportRaw(exporters->FbxULongLongExporter, &val, sizeof(FbxULongLong));
}

void Export(Exporters* exporters, FbxHalfFloat val)
{
    ExportRaw(exporters->FbxHalfFloatExporter, &val, sizeof(FbxHalfFloat));
}

void Export(Exporters* exporters, FbxBool val)
{
    ExportRaw(exporters->FbxBoolExporter, &val, sizeof(FbxBool));
}

void Export(Exporters* exporters, FbxInt val)
{
    ExportRaw(exporters->FbxIntExporter, &val, sizeof(FbxInt));
}

void Export(Exporters* exporters, FbxFloat val)
{
    ExportRaw(exporters->FbxFloatExporter, &val, sizeof(FbxFloat));
}

void Export(Exporters* exporters, FbxDouble val)
{
    ExportRaw(exporters->FbxDoubleExporter, &val, sizeof(FbxDouble));
}

// FbxDouble2
// FbxDouble3
// FbxDouble4
// FbxDouble4x4
// FbxString
// eFbxEnum
// eFbxTime
// eFbxDistance
// eFbxEnum
// eFbxReference
// eFbxBlob
// eFbxDateTime
// eFbxTypeCount
