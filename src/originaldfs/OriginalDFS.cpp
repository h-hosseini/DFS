/*
 * Copyright (C) 2019 Hedayat Hosseini.
 */

#include "OriginalDFS.h"

OriginalDFS::OriginalDFS(Graph g, unsigned int numNodes)
{

  this->numNodes = numNodes;
  node = new (node_t[numNodes]);

  for(unsigned int u = 0; u < numNodes; u++){
    node[u].color = white;
    node[u].parent = nullptr;
  }

  time = 0;

  for(unsigned int u = 0; u < numNodes; u++){
    if (node[u].color == white)
      dfsVisit(g, u);
  }
}

void OriginalDFS::dfsVisit(Graph g, unsigned int u)
{
  node[u].color = gray;
  node[u].discoveryTime = ++time;

  unsigned int *neighbors = g.getNeighbors(u);
  for (unsigned int i = 0; i < g.getNumNeighbors(u); i++){
    unsigned int v = neighbors[i];
    node[v].parent = &node[u];
    dfsVisit(g,v);
  }
  node[u].color = black;
  node[u].finishingTime = ++time;
}
