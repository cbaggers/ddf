#include "include/exporters.h"

Buffer* MakeBuffer(const char* path)
{
    return new Buffer();
}

Exporters* InitExporters(const char* path)
{
    Exporters* r = new Exporters();
    NodeExporter* ne = new NodeExporter();
    ne->buff = MakeBuffer(path);
    return r;
}
