#include <bits/stdc++.h>
using namespace std;

bool DetectCycle(int node, vector<int> adj[],
                 vector<bool>& path,
                 vector<bool>& visited,
                 vector<int>& currentPath,
                 vector<int>& cycle)
{
    visited[node] = 1;
    path[node] = 1;

    currentPath.push_back(node);

    for(int j = 0; j < adj[node].size(); j++)
    {
        int neighbour = adj[node][j];

        if(path[neighbour])
        {
            int k = 0;

            while(currentPath[k] != neighbour)
                k++;

            for(int x = k; x < currentPath.size(); x++)
                cycle.push_back(currentPath[x]);

            return true;
        }

        else if(!visited[neighbour])
        {
            if(DetectCycle(neighbour, adj, path,
                           visited, currentPath, cycle))
            {
                return true;
            }
        }
    }

    path[node] = 0;
    currentPath.pop_back();

    return false;
}

int main()
{
    int V, E;

    cin >> V >> E;

    vector<int> adj[V];

    // Input edges
    for(int i = 0; i < E; i++)
    {
        int u, v;

        cin >> u >> v;

        adj[u].push_back(v);
    }

    // Display Graph
    cout << "Graph:\n";

    for(int i = 0; i < V; i++)
    {
        cout << i << " -> ";

        for(int j = 0; j < adj[i].size(); j++)
        {
            cout << adj[i][j] << " ";
        }

        cout << endl;
    }

    vector<bool> path(V, 0);
    vector<bool> visited(V, 0);

    vector<int> currentPath;
    vector<int> cycle;

    bool deadlock = false;

    // Detect cycle
    for(int i = 0; i < V; i++)
    {
        if(!visited[i])
        {
            if(DetectCycle(i, adj, path,
                           visited, currentPath, cycle))
            {
                deadlock = true;
                break;
            }
        }
    }

    // Result
    if(deadlock)
    {
        cout << "\nSystem is in DEADLOCK state.\n";

        cout << "Detected Cycle: ";

        for(int i = 0; i < cycle.size(); i++)
        {
            cout << cycle[i] << " -> ";
        }

        cout << cycle[0] << endl;
    }
    else
    {
        cout << "\nSystem is NOT in DEADLOCK state.\n";
    }

    return 0;
}