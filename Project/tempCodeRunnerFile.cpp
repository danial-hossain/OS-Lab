#include <bits/stdc++.h>
using namespace std;

set<vector<int>> allCycles;

void DetectCycle(int node, vector<int> adj[],
                 vector<bool>& path,
                 vector<bool>& visited,
                 vector<int>& currentPath)
{
    visited[node] = 1;
    path[node] = 1;
    currentPath.push_back(node);

    for(int j=0; j<adj[node].size(); j++)
    {
        int neighbour = adj[node][j];

        if(path[neighbour])
        {
            vector<int> cycle;

            int k = 0;

            while(currentPath[k] != neighbour)
                k++;

            for(int x=k; x<currentPath.size(); x++)
                cycle.push_back(currentPath[x]);

            allCycles.insert(cycle);
        }

        else if(!visited[neighbour])
        {
            DetectCycle(neighbour, adj, path,
                        visited, currentPath);
        }
    }

    path[node] = 0;
    currentPath.pop_back();
}

vector<vector<int>> isCyclic(int V, vector<int> adj[])
{
    allCycles.clear();

    vector<bool> path(V, 0);
    vector<bool> visited(V, 0);
    vector<int> currentPath;

    for(int i=0; i<V; i++)
    {
        DetectCycle(i, adj, path,
                    visited, currentPath);
    }

    vector<vector<int>> result;

    for(auto cycle : allCycles)
        result.push_back(cycle);

    return result;
}

int main()
{
    int V, E;

    cin >> V >> E;

    vector<int> adj[V];

    for(int i=0; i<E; i++)
    {
        int u, v;
        cin >> u >> v;

        adj[u].push_back(v);
    }

    cout << "Graph:\n";

    for(int i=0; i<V; i++)
    {
        cout << i << " -> ";

        for(int j=0; j<adj[i].size(); j++)
        {
            cout << adj[i][j] << " ";
        }

        cout << endl;
    }

    vector<vector<int>> result = isCyclic(V, adj);

    cout << "\nDeadlock Cycles:\n";

    if(result.empty())
    {
        cout << "No deadlock cycle found.\n";
    }
    else
    {
        for(int i=0; i<result.size(); i++)
        {
            cout << "Cycle " << i+1 << ": ";

            for(int node : result[i])
                cout << node << " -> ";

            cout << result[i][0] << endl;
        }
    }

    return 0;
}