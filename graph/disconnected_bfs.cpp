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

void bfs(vector<int> adj[], int s, vector<bool> &visited )
{ 
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

void bfsDisconnected(vector<int> adj[], int v)
{
    vector<bool> visited(v + 1, false);  
    int count = 0;
    for(int i=0; i<v; i++)
    {
        if(visited[i]==false)
        {
            count++;
            bfs(adj, i, visited);
        }
    }
    cout<<endl<<"*******************************"<<endl;
    cout<<"Number od Disconected graphs are : "<<count<<endl;
    cout<<endl<<"*******************************"<<endl;

}



int main()
{
    int v = 9;
    vector<int> adj[v];
    addEdge(adj, 0, 1);
    addEdge(adj, 0, 2);
    addEdge(adj, 2, 1);
    addEdge(adj, 3, 4);
    addEdge(adj, 5, 6);
    addEdge(adj, 5, 7);
    addEdge(adj, 7, 8);
    printGraph(adj, v);

    cout<<"BFS : ";
    int source;
    cin>>source;
    bfsDisconnected(adj, v);
    return 0;
}