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
typedef unsigned int VertexIndex_t; //An index to show a vertex in a graph
typedef unsigned int GraphSize_t;  // To show the number of nodes in a graph

class IGraph
{
public:

    virtual GraphSize_t getNumNodes() = 0;

    virtual VertexIndex_t *getNeighbors(VertexIndex_t u) = 0;

    virtual GraphSize_t getNumNeighbors(VertexIndex_t u) = 0;

    virtual bool hasEdge(VertexIndex_t u, VertexIndex_t v) = 0;

    virtual bool areNeighbors(VertexIndex_t u, VertexIndex_t v) = 0;

};
#endif // ifndef DFS_CONTRACT_IGRAPH_H_
