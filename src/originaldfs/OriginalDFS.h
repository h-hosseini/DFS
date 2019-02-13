/*
 * Copyright (C) 2019 Hedayat Hosseini.
 */

 #ifndef DFS_ORIGINALDFS_DFS_H_
 #define DFS_ORIGINALDFS_DFS_H_

//#include "../contract/IGraph.h"
#include "../graph/Graph.h"

 class OriginalDFS
 {
 protected:
   enum colors{
     white,
     gray,
     black
   };

   struct NodeStruct{
     VertexIndex_t nodeIndex;
     enum colors color;
     //VertexIndex_t parent;
     struct NodeStruct *parent;
     unsigned int discoveryTime;
     unsigned int finishingTime;
   };
   typedef struct NodeStruct Node_t;
   Node_t *node; //A pointer to refer to the graph nodes

   unsigned int time;
   int numNodes;  //Number of nodes in the graph

 public:
   OriginalDFS()
    : time(0)
    , numNodes(0)
    , node(nullptr)
   {};

   OriginalDFS(const Graph &g);
   ~OriginalDFS();

protected:

    virtual void init(const Graph &g);

    virtual void startDFS(const Graph &g);

    virtual void dfsVisit(const Graph &g, int u);

public:

    virtual VertexIndex_t getParent(VertexIndex_t u) const;

    virtual unsigned int getDiscoveryTime(VertexIndex_t u) const;

    virtual unsigned int getFinishingTime(VertexIndex_t u) const;

 };
#endif // ifndef DFS_ORIGINALDFS_ORIGINALDFS_H_
