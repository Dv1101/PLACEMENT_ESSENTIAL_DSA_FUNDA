#include<iostream>
#include<vector>
#include<queue>
using namespace std;

void addEdge(vector<int> adj[], int u, int v)
{
    adj[v].push_back(u);
    adj[u].push_back(v);
}

void printGraph(vector<int> adj[], int v)
{
    cout << "Vertices -> Edges" << endl;
    for (int i = 0; i < v; i++)
    {
        cout << "Vertice : " << i << " -> ";
        for (auto x : adj[i])
        {
            cout << x << " ";
        }
        cout << endl;
    }
}

void dfss(vector<int> adj[], int s, vector<bool>& visited)
{
    visited[s] = true;
    cout << s << " ";
    for (auto u : adj[s])
    {
        if (visited[u] == false)
        {
            dfss(adj, u, visited);
        }
    }
}

void dfs(vector<int> adj[], int v, int s)
{
    vector<bool> visited(v, false);
    for (int i = 0; i < v; i++)
    {
        if (visited[i] == false)
        {
            dfss(adj, i, visited);
        }
    }
}

int main()
{
    int v = 4;
    vector<int> adj[v];
    addEdge(adj, 0, 1);
    addEdge(adj, 0, 2);
    addEdge(adj, 2, 1);
    addEdge(adj, 3, 2);
    printGraph(adj, v);

    cout << "DFS: Enter source vertex: ";
    int source;
    cin >> source;
    dfs(adj, v, source);
    return 0;
}
