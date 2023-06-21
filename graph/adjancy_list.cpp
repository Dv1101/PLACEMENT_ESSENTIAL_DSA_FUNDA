#include<iostream>
#include<vector>
using namespace std;

void addEdge(vector<int> adj[], int u, int v)
{
    adj[v].push_back(u);
    adj[u].push_back(v);

}

void printGraph(vector<int> adj[], int v)
{
    cout<<"Vertices -> Edges"<<endl;
    for(int i=0; i<v; i++)
    {
        cout<<"Vertice : "<<i<<" -> ";
        for(auto x : adj[i])
        {
            cout<<x<<" ";
        }
        cout<<endl;
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
    return 0;
}