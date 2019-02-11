/*
 * Copyright (C) 2019 Hedayat Hosseini.
 */

#ifndef DFS_GRAPH_GRAPH_H_
#define DFS_GRAPH_GRAPH_H_

#include "../contract/IGraph.h"

class Graph : public IGraph
{
private:
  GraphSize_t numNodes;
  Edge_t **edges;

public:
  Graph()
    : numNodes(0)
    , edges(nullptr)
    {};

  Graph(GraphSize_t numNodes);

  ~Graph();

  virtual GraphSize_t getNumNodes() override;

  virtual GraphSize_t getNumNeighbors(VertexIndex_t u) override;

  virtual VertexIndex_t *getNeighbors(VertexIndex_t u) override;

  virtual bool hasEdge(VertexIndex_t u, VertexIndex_t v) override;

  virtual bool areNeighbors(VertexIndex_t u, VertexIndex_t v) override;

  //virtual void setNumNodes(GraphSize_t numNodes);

  virtual bool setEdge(VertexIndex_t u, VertexIndex_t v, float weight = 0);

};
#endif  // ifndef DFS_GRAPH_GRAPH_H_
