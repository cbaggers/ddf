#pragma once
#include <stdio.h>
#include <fbxsdk.h>
#include <fstream.h>

//------------------------------------------------------------
// Export logic

struct Buffer
{
    FbxUInt8* Data;
    FbxUInt32 Size;
    FbxUInt32 Pos;
};

struct NodeExporter
{
    Buffer* Buff;
    ifstream FileStream;
};

struct Exporters
{
    NodeExporter* FbxBoolExporter;
    NodeExporter* FbxCharExporter;
    NodeExporter* FbxDoubleExporter;
    NodeExporter* FbxFloatExporter;
    NodeExporter* FbxHalfFloatExporter;
    NodeExporter* FbxInt16Exporter;
    NodeExporter* FbxInt32Exporter;
    NodeExporter* FbxInt64Exporter;
    NodeExporter* FbxInt8Exporter;
    NodeExporter* FbxIntExporter;
    NodeExporter* FbxLongExporter;
    NodeExporter* FbxLongLongExporter;
    NodeExporter* FbxShortExporter;
    NodeExporter* FbxUCharExporter;
    NodeExporter* FbxUInt16Exporter;
    NodeExporter* FbxUInt32Exporter;
    NodeExporter* FbxUInt64Exporter;
    NodeExporter* FbxUInt8Exporter;
    NodeExporter* FbxUIntExporter;
    NodeExporter* FbxULongExporter;
    NodeExporter* FbxULongLongExporter;
    NodeExporter* FbxUShortExporter;
};

Buffer* MakeBuffer(const char* path);

Exporters* InitExporters(const char* path);

void Export(Exporters* exporters, FbxBool val);
void Export(Exporters* exporters, FbxChar val);
void Export(Exporters* exporters, FbxDouble val);
void Export(Exporters* exporters, FbxFloat val);
void Export(Exporters* exporters, FbxHalfFloat val);
void Export(Exporters* exporters, FbxInt val);
void Export(Exporters* exporters, FbxLong val);
void Export(Exporters* exporters, FbxLongLong val);
void Export(Exporters* exporters, FbxShort val);
void Export(Exporters* exporters, FbxUChar val);
void Export(Exporters* exporters, FbxUInt val);
void Export(Exporters* exporters, FbxUShort val);
