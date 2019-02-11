/*
 * Copyright (C) 2019 Hedayat Hosseini.
 */

#include "Graph.h"

Graph::Graph(GraphSize_t numNodes)
{
  this->numNodes = numNodes;
  edges = new (Edge_t *[numNodes]);
  for(int i = 0; i < numNodes; i++){
    edges[i] = new (Edge_t[numNodes]);
    for(int j = 0; j < numNodes; j++){
      edges[i][j] = 0;
    }
  }
}

GraphSize_t Graph::getNumNodes()
{
  return numNodes;
}

GraphSize_t Graph::getNumNeighbors(VertexIndex_t u)
{
  GraphSize_t numNeighbors = 0;
  for(int v = 0; v < numNodes; v++){
    if(edges[u][v] != 0)
      numNeighbors++;
  }

  return numNeighbors;
}

VertexIndex_t *Graph::getNeighbors(VertexIndex_t u)
{
  VertexIndex_t *neighbors = new(VertexIndex_t[getNumNeighbors(u)]);
  int i = 0;
  for(int v = 0; v < numNodes; v++){
    if(edges[u][v] != 0)
      neighbors[i++] = v;
  }

  return neighbors;
}

bool Graph::hasEdge(VertexIndex_t u, VertexIndex_t v)
{
  if(edges[u][v] != 0)
    return true;

  return false;
}

bool Graph::areNeighbors(VertexIndex_t u, VertexIndex_t v)
{
  return hasEdge(u,v);

}

/*void Graph::setNumNodes(GraphSize_t numNodes)
{
    this->numNodes = numNodes;
}
*/
bool Graph::setEdge(VertexIndex_t u, VertexIndex_t v, float weight)
{
    if((u < numNodes) && (v < numNodes)){
        edges[u][v] = weight;
        return true;
    }else{
        return false;
    }
}


Graph::~Graph()
{


}
