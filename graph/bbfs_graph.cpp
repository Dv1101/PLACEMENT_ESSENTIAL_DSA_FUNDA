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

void bfs(vector<int> adj[], int v, int s )
{
    vector<bool> visited(v + 1, false);  
    queue<int> q;
    visited[s] = true;
    q.push(s);
    while(!q.empty())
    {
        int poppedEle = q.front();
        q.pop();
        cout<<poppedEle<<" ";

        for(int v: adj[poppedEle])
        {
            if(visited[v]==false)
            {
                visited[v]=true;
                q.push(v);
            }
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

    cout<<"BFS : Enter source vertice : ";
    int source;
    cin>>source;
    bfs(adj, v, source);
    return 0;
}