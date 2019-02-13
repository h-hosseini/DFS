/*
 * Copyright (C) 2019 Hedayat Hosseini.
 */

#include "SourceBasedDFS.h"

SourceBasedDFS::SourceBasedDFS(const Graph &g, VertexIndex_t src)
{
    init(g);
    startSourceBasedDFS(g, src);

}

void SourceBasedDFS::startSourceBasedDFS(const Graph &g, VertexIndex_t src)
{
    dfsVisit(g, src);
}
