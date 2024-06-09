#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <ctime>
#include <cstdlib>
#include <iomanip>

using namespace std;
void topologicalSortUtil(int v, vector<vector<int>> &adj, vector<bool> &visited, stack<int> &Stack)
{
    visited[v] = true;
    for (int i : adj[v])
    {
        if (!visited[i])
            topologicalSortUtil(i, adj, visited, Stack);
    }
    Stack.push(v);
}

void topologicalSort(vector<vector<int>> &adj, int V)
{
    stack<int> Stack;
    vector<bool> visited(V, false);

    for (int i = 0; i < V; i++)
    {
        if (!visited[i])
            topologicalSortUtil(i, adj, visited, Stack);
    }

    while (!Stack.empty())
    {
        cout << Stack.top() << " ";
        Stack.pop();
    }
}

int main()
{
    int ch;
    int V, E;
    while (1)
    {
        cout << "\nChoose the type of graph you want to sort topologically:";
        cout << "\n1. Directed Graph";
        cout << "\n2. Exit";
        cout << "\nEnter your choice\n";
        cin >> ch;
        if (ch == 2)
        {
            cout << "Exiting the program.\n";
            break;
        }
        switch (ch)
        {
        case 1:
        {
            cout << "Enter the number of vertices\n";
            cin >> V;
            cout << "Enter the number of edges\n";
            cin >> E;

            vector<vector<int>> adj(V);
            cout << "Enter the edges (format: source destination)\n";
            for (int i = 0; i < E; i++)
            {
                int src, dest;
                cin >> src >> dest;
                adj[src].push_back(dest);
            }

            cout << "Performing Topological Sort...\n";

            clock_t tStart = clock();
            topologicalSort(adj, V);
            clock_t tEnd = clock();

            cout << "\nTime taken for Topological Sort is " << fixed << setprecision(5)
                 << (double)(tEnd - tStart) / CLOCKS_PER_SEC << " seconds\n";
            break;
        }
        default:
            cout << "Invalid choice\n";
            break;
        }
    }

    return 0;
}
