/*
 * Copyright (C) 2019 Hedayat Hosseini.
 */

#ifndef DFS_GRAPH_GRAPH_H_
#define DFS_GRAPH_GRAPH_H_

#include "../contract/IGraph.h"
#include <vector>

using namespace std;

typedef vector<vector<Edge_t>> Matrix;

class Graph : public IGraph
{
private:
  int numNodes;
  Edge_t **edges;

public:
  Graph()
    : numNodes(0)
    , edges(nullptr)
    {};

  Graph(int numNodes);

  Graph(Matrix &matrix);

  //Graph(int numNodes, void *matrix);

  ~Graph();

  virtual int getNumNodes() const override;

  virtual int getNumNeighbors(VertexIndex_t u) const override;

  virtual VertexIndex_t *getNeighbors(VertexIndex_t u) const override;

  virtual bool hasEdge(VertexIndex_t u, VertexIndex_t v) const override;

  virtual bool areNeighbors(VertexIndex_t u, VertexIndex_t v) const override;

  virtual bool setEdge(VertexIndex_t u, VertexIndex_t v, float weight = 0);

};
#endif  // ifndef DFS_GRAPH_GRAPH_H_
