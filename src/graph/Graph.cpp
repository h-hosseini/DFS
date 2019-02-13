/*
 * Copyright (C) 2019 Hedayat Hosseini.
 */

#include "Graph.h"
#include <iostream>

Graph::Graph(int numNodes)
{
  this->numNodes = numNodes;
  edges = new Edge_t *[numNodes];
  for(int i = 0; i < numNodes; i++){
    edges[i] = new Edge_t[numNodes];
    for(int j = 0; j < numNodes; j++){
      edges[i][j] = 0;
    }
  }
}

Graph::Graph(Matrix &matrix) : Graph(matrix.size())
{
    //TODO : matrix must be symmetric, i.e m.size() == m[0].size()
    for(int i = 0; i < numNodes; i++)
        for(int j = 0; j < numNodes; j++)
            edges[i][j] = matrix[i][j];

}

/*Graph::Graph(int numNodes, void *mat) : Graph(numNodes)
{
    //First, we cast mat to 2D array
    Edge_t (*matrix)[numNodes][numNodes] = (Edge_t (*)[numNodes][numNodes]) mat;

    for(int i = 0; i < numNodes; i++)
        for(int j = 0; j < numNodes; j++)
            edges[i][j] = (*matrix)[i][j];
}
*/
int Graph::getNumNodes() const
{
  return numNodes;
}

int Graph::getNumNeighbors(VertexIndex_t u) const
{
  int numNeighbors = 0;
  for(int v = 0; v < numNodes; v++){
    if(edges[u][v] != 0)
      numNeighbors++;
  }

  return numNeighbors;
}

VertexIndex_t *Graph::getNeighbors(VertexIndex_t u) const
{
    VertexIndex_t *neighbors = nullptr;

    if (getNumNeighbors(u) > 0){
        neighbors = new VertexIndex_t[getNumNeighbors(u)];
        int i = 0;
        for(int v = 0; v < numNodes; v++){
            if(edges[u][v] != 0)
            neighbors[i++] = v;
        }
    }

  return neighbors;
}

bool Graph::hasEdge(VertexIndex_t u, VertexIndex_t v) const
{
  if(edges[u][v] != 0)
    return true;

  return false;
}

bool Graph::areNeighbors(VertexIndex_t u, VertexIndex_t v) const
{
  return hasEdge(u,v);

}

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
    for(int i = 0; i < numNodes; i++){
        if (numNodes > 1)
            delete []edges[i];
        else if(numNodes == 1)
            delete edges[i];
        edges[i] = nullptr;
    }

    if (numNodes > 1)
        delete [] edges;
    else if (numNodes == 1)
        delete edges;
    edges = nullptr;
}
