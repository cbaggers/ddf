#pragma once
#include <stdio.h>

//------------------------------------------------------------
// Export logic

struct Buffer
{
    void* Data;
    FILE* file;
};

struct NodeExporter
{
    Buffer* buff;
};

struct Exporters
{
    NodeExporter* Node;
};

Buffer* MakeBuffer(const char* path);

Exporters* InitExporters(const char* path);
