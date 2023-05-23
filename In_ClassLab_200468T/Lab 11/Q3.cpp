#include <iostream>
#include <climits>

#define V 6 // Number of vertices in the graph

int minKey(int key[], bool mstSet[])
{
    int min = INT_MAX, min_index;

    for (int v = 0; v < V; ++v)
    {
        if (!mstSet[v] && key[v] < min)
        {
            min = key[v];
            min_index = v;
        }
    }

    return min_index;
}

void printMST(int parent[], int graph[V][V])
{
    std::cout << "Edge \tWeight\n";
    for (int i = 1; i < V; ++i)
    {
        std::cout << parent[i] << " - " << i << "\t" << graph[i][parent[i]] << "\n";
    }
}

void primMST(int graph[V][V])
{
    int parent[V]; // Array to store constructed MST
    int key[V];    // Key values used to pick the minimum weight edge
    bool mstSet[V]; // To represent set of vertices included in MST

    for (int i = 0; i < V; ++i)
    {
        key[i] = INT_MAX;
        mstSet[i] = false;
    }

    key[0] = 0;     // Make key 0 so that this vertex is picked as the first vertex
    parent[0] = -1; // First node is always the root of MST

    for (int count = 0; count < V - 1; ++count)
    {
        int u = minKey(key, mstSet); // Pick the minimum key vertex from the set of vertices not yet included in MST
        mstSet[u] = true;            // Add the picked vertex to the MST set

        for (int v = 0; v < V; ++v)
        {
            if (graph[u][v] && !mstSet[v] && graph[u][v] < key[v])
            {
                parent[v] = u;
                key[v] = graph[u][v];
            }
        }
    }

    printMST(parent, graph);
}

int main()
{
    int graph[V][V] = {{0, 3, 0, 0, 0, 1},
                       {3, 0, 2, 1, 10, 0},
                       {0, 2, 0, 3, 0, 5},
                       {0, 1, 3, 0, 5, 0},
                       {0, 10, 0, 5, 0, 4},
                       {1, 0, 5, 0, 4, 0}};

    primMST(graph);

    return 0;
}

