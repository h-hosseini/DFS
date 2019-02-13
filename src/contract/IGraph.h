/*
 * Copyright (C) 2019 Hedayat Hosseini.
 */

#ifndef DFS_CONTRACT_IGRAPH_H_
#define DFS_CONTRACT_IGRAPH_H_

/*
 * If edge(u,v) !=0, there is an edge between u and v.
 * Otherwise, value of edge(u,v) is the weight of the edge between u and v.
 */
typedef float Edge_t;

/* An index to show a vertex in a graph
 * If a node has not any parent, we show its parent by -1
 */
typedef int VertexIndex_t;

class IGraph
{
public:

    virtual int getNumNodes() const = 0;

    virtual VertexIndex_t *getNeighbors(VertexIndex_t u) const = 0;

    virtual int getNumNeighbors(VertexIndex_t u) const = 0;

    virtual bool hasEdge(VertexIndex_t u, VertexIndex_t v) const = 0;

    virtual bool areNeighbors(VertexIndex_t u, VertexIndex_t v) const = 0;

};
#endif // ifndef DFS_CONTRACT_IGRAPH_H_
