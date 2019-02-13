/*
 * Copyright (C) 2019 Hedayat Hosseini.
 */

#ifndef DFS_SRC_SOURCEBASEDDFS_SOURCEBASEDDFS_H
#define DFS_SRC_SOURCEBASEDDFS_SOURCEBASEDDFS_H

#include "../originalDFS/OriginalDFS.h"

class SourceBasedDFS : public OriginalDFS
{

public:
    SourceBasedDFS(const Graph &g, VertexIndex_t src);

protected:
    void startSourceBasedDFS(const Graph &g, VertexIndex_t src);

    //virtual void startDFS(const Graph &g) override;
};

#endif // DFS_SRC_SOURCEBASEDDFS_SOURCEBASEDDFS_H
