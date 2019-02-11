/*
 * Copyright (C) 2019 Hedayat Hosseini.
 */

 #ifndef DFS_ORIGINALDFS_DFS_H_
 #define DFS_ORIGINALDFS_DFS_H_

//#include "../contract/IGraph.h"
#include "../graph/Graph.h"

 class OriginalDFS
 {
 private:
   enum colors{
     white,
     gray,
     black
   };

   struct nodeStruct{
     VertexIndex_t nodeIndex;
     enum colors color;
     struct nodeStruct *parent;
     unsigned int discoveryTime;
     unsigned int finishingTime;
   };
   typedef struct nodeStruct node_t;
   node_t *node; //A pointer to refer to the graph nodes

   unsigned int time;
   GraphSize_t numNodes;  //Number of nodes in the graph

 public:
   OriginalDFS()
    : time(0)
    , numNodes(0)
    , node(nullptr)
   {};

   OriginalDFS(Graph g, unsigned int numNodes);

   void dfsVisit(Graph g, unsigned int u);










 };
#endif // ifndef DFS_ORIGINALDFS_ORIGINALDFS_H_
