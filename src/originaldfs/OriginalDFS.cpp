/*
 * Copyright (C) 2019 Hedayat Hosseini.
 */

#include "OriginalDFS.h"

OriginalDFS::OriginalDFS(const Graph &g)
{
    init(g);
    startDFS(g);
}

void OriginalDFS::init(const Graph &g)
{
    numNodes = g.getNumNodes();
    node = new Node_t[numNodes];

    for(int u = 0; u < numNodes; u++){
        node[u].nodeIndex = u;
        node[u].color = white;
        //node[u].parent = -1;
        node[u].parent = nullptr;
        node[u].discoveryTime = 0; //The valid discovery time is start from 1 in the DFS algorithm.
        node[u].finishingTime = 0; //The valid discovery time is start from 1 in the DFS algorithm.
    }

    time = 0;
}
void OriginalDFS::startDFS(const Graph &g)
{
    for(int u = 0; u < numNodes; u++){
        if (node[u].color == white)
            dfsVisit(g, u);
  }
}

void OriginalDFS::dfsVisit(const Graph &g, int u)
{
  node[u].color = gray;
  node[u].discoveryTime = ++time;

  VertexIndex_t *neighbors = g.getNeighbors(u);
  VertexIndex_t v;
  for (int i = 0; i < g.getNumNeighbors(u); i++){
    v = neighbors[i];
    if (node[v].color == white){
        //node[v].parent = u;
        node[v].parent = node + u;
        dfsVisit(g,v);
    }
  }
  node[u].color = black;
  node[u].finishingTime = ++time;

  if (g.getNumNeighbors(u) > 1)
    delete [] neighbors;
  else if (g.getNumNeighbors(u) == 1)
    delete neighbors;
  neighbors = nullptr;
}

VertexIndex_t OriginalDFS::getParent(VertexIndex_t u) const{

    //return node[u].parent;

    if (node[u].parent)
        return node[u].parent->nodeIndex;
    else
        return -1; //u has not any parent
}

unsigned int OriginalDFS::getDiscoveryTime(VertexIndex_t u) const{
    return node[u].discoveryTime;
}

unsigned int OriginalDFS::getFinishingTime(VertexIndex_t u) const{
    return node[u].finishingTime;
}

OriginalDFS::~OriginalDFS()
{
    if (numNodes > 1)
        delete [] node;
    else if (numNodes == 1)
        delete node;
    node = nullptr;
}
