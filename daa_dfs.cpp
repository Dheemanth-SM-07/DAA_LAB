#include <iostream>
#include <vector>
#include <stack>
#include <ctime>
using namespace std;

class Graph 
{
    int V;
    vector<vector<int>> adj;
    bool directed;

public:
    Graph(int V, bool directed);
    void addEdge(int v, int w);
    void DFS(int v);
};

Graph::Graph(int V, bool directed) 
{
    this->V = V;
    this->directed = directed;
    adj.resize(V);
}

void Graph::addEdge(int v, int w)
{
    adj[v].push_back(w);
    if (!directed) 
    {
        adj[w].push_back(v);
    }
}

void Graph::DFS(int v)
{
    vector<bool> visited(V, false);
    stack<int> stack;
    stack.push(v);

    while (!stack.empty()) 
    {
        v = stack.top();
        stack.pop();

        if (!visited[v]) 
        {
            cout << v << " ";
            visited[v] = true;
        }

        for (auto i = adj[v].rbegin(); i != adj[v].rend(); ++i)
        {
            if (!visited[*i]) {
                stack.push(*i);
            }
        }
    }
    cout << endl;
}

void displayMenu() 
{
    cout << "Graph Traversal Menu:\n";
    cout << "1. DFS for Directed Graph\n";
    cout << "2. DFS for Undirected Graph\n";
    cout << "5. Exit\n";
    cout << "Enter your choice: ";
}

int main() 
{
    int choice, V, v, w, startVertex;
    bool directed;

    while (true) 
    {
        displayMenu();
        cin >> choice;

        if (choice == 5) 
        {
            break;
        }

        cout << "Enter number of vertices: ";
        cin >> V;
        directed = (choice == 1);

        Graph g(V, directed);

        cout << "Enter edges (format: v w). Enter -1 -1 to stop adding edges.\n";
        while (true) {
            cin >> v >> w;
            if (v == -1 && w == -1) 
            {
                break;
            }
            g.addEdge(v, w);
        }

        cout << "Enter starting vertex: ";
        cin >> startVertex;

        switch (choice) 
        {
            case 1: 
            {
                clock_t tStart = clock();
                cout << "Depth First Traversal for Directed Graph starting from vertex " << startVertex << ":\n";
                g.DFS(startVertex);
                clock_t tEnd = clock();
                cout << "Time taken for DFS (Directed): " << fixed << (double)(tEnd - tStart) / CLOCKS_PER_SEC << " seconds\n";
                break;
            }
            case 2: 
            {
                clock_t tStart = clock();
                cout << "Depth First Traversal for Undirected Graph starting from vertex " << startVertex << ":\n";
                g.DFS(startVertex);
                clock_t tEnd = clock();
                cout << "Time taken for DFS (Undirected): " << fixed << (double)(tEnd - tStart) / CLOCKS_PER_SEC << " seconds\n";
                break;
            }
            default:
                cout << "Invalid choice! Please try again.\n";
        }
    }

    return 0;
}

// Graph Traversal Menu:
// 1. DFS for Directed Graph
// 2. DFS for Undirected Graph
// 5. Exit
// Enter your choice: 1
// Enter number of vertices: 5
// Enter edges (format: v w). Enter -1 -1 to stop adding edges.
// 0 1
// 0 2
// 1 3
// 1 4
// 2 4
// -1 -1
// Enter starting vertex: 0
// Depth First Traversal for Directed Graph starting from vertex 0:
// 0 2 4 1 3 
// Time taken for DFS (Directed): 0.0000 seconds
