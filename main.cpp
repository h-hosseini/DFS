#include <iostream>
#include "src/originaldfs/OriginalDFS.h"
#include "src/graph/Graph.h"

using namespace std;

int main()
{
    //Matrix mat0(4, vector<Edge_t>(4, 0));
    Matrix mat1 {
                    {0, 1, 1, 0},
                    {0, 0, 0, 1},
                    {0, 1, 0, 0},
                    {0, 0, 1, 0}
                };
    Graph g(mat1);
    //Edge_t mat2[4][4] = {{0, 1, 1, 0}, {0, 0, 0, 1}, {0, 1, 0, 0}, {0, 0, 1, 0}};
    //Graph g(4, mat2);

    //Matrix
    //g.setEdge(0,1);
    //g.setEdge(1,2);

    cout << "numNodes : " << g.getNumNodes()<< endl;

    /////////////////////////////////////////////////
    VertexIndex_t *neighbors = g.getNeighbors(0);
    cout << "neighbors 0 = ";
    for(int i = 0; i < g.getNumNeighbors(0); i++){
        cout << neighbors[i] << " ";
    }
    cout << endl;
    delete [] neighbors;
    neighbors = nullptr;

    ///////////////////////////////////
    neighbors = g.getNeighbors(1);
    cout << "neighbors 1 = ";
    for(int i = 0; i < g.getNumNeighbors(1); i++){
        cout << neighbors[i] << " ";
    }
    cout << endl;
    delete [] neighbors;
    neighbors = nullptr;

    ///////////////////////////////////
    neighbors = g.getNeighbors(2);
    cout << "neighbors 2 = ";
    for(int i = 0; i < g.getNumNeighbors(2); i++){
        cout << neighbors[i] << " ";
    }
    cout << endl;
    delete [] neighbors;
    neighbors = nullptr;

    ////////////////////////////////////
    neighbors = g.getNeighbors(3);
    cout << "neighbors 3 = ";
    for(int i = 0; i < g.getNumNeighbors(3); i++){
        cout << neighbors[i] << " ";
    }
    cout << endl;
    delete [] neighbors;
    neighbors = nullptr;

    for (int u = 0; u < g.getNumNodes(); u++)
        cout << "numNeighbors " << u << " : " << g.getNumNeighbors(u) << endl;

    // Original DFS
    OriginalDFS originalDFS(g);
    for (int u = 0; u < g.getNumNodes(); u++)
        cout << "Node(" << u << "): Parent = " << originalDFS.getParent(u) << ", Dscovery time = " << originalDFS.getDiscoveryTime(u) << ", Finishing time = " << originalDFS.getFinishingTime(u) << endl;

    return 0;
}
