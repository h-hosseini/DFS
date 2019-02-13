#include <iostream>
#include "src/originaldfs/OriginalDFS.h"
#include "src/sourcebaseddfs/SourceBasedDFS.h"
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
    cout << "--------------------------------------------" << endl;;

    for (int u = 0; u < g.getNumNodes(); u++)
        cout << "numNeighbors " << u << " : " << g.getNumNeighbors(u) << endl;
    cout << "--------------------------------------------" << endl;;

    VertexIndex_t *neighbors;
    for (int node = 0; node < g.getNumNodes(); node++){
        neighbors = g.getNeighbors(node);
        cout << "neighbors " << node << " = ";
        for(int i = 0; i < g.getNumNeighbors(node); i++){
            cout << neighbors[i] << " ";
        }
        cout << endl;
        if (g.getNumNeighbors(node) > 1)
            delete [] neighbors;
        else if (g.getNumNeighbors(node) == 1)
            delete neighbors;
        neighbors = nullptr;
    }
    cout << "--------------------------------------------" << endl;;

    // Original DFS
    OriginalDFS originalDFS(g);
    cout << "Original DFS" << endl;
    for (int u = 0; u < g.getNumNodes(); u++)
        cout << "Node(" << u << "): Parent = " << originalDFS.getParent(u) << ", Dscovery time = " << originalDFS.getDiscoveryTime(u) << ", Finishing time = " << originalDFS.getFinishingTime(u) << endl;
    cout << "--------------------------------------------" << endl;;

   // Source based DFS
    SourceBasedDFS sourceBasedDFS(g, 3);
    cout << "Source based DFS (from node #3)" << endl;
    for (int u = 0; u < g.getNumNodes(); u++)
        cout << "Node(" << u << "): Parent = " << sourceBasedDFS.getParent(u) << ", Dscovery time = " << sourceBasedDFS.getDiscoveryTime(u) << ", Finishing time = " << sourceBasedDFS.getFinishingTime(u) << endl;

    return 0;
}
