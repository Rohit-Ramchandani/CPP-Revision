#include<bits/stdc++.h>
using namespace std;

int vertices = 4;
int mat[4][4];
vector<vector<int>> edge = {{0,1},{0,2},{0,3},{1,2},{2,3}};
vector<int> adj[4];

void dfs(int curr, vector<int>& visited, vector<int> adj[], vector<int>& ans)
{
    ans.push_back(curr);
    visited[curr] = 1;

    for(auto neigh : adj[curr])
    {
        if(!visited[neigh])
        {
            dfs(neigh, visited, adj, ans);
        }
    }
}

vector<int> dfsOfGraph(int V, vector<int> adj[])
{
    vector<int> ans;
    vector<int> visited(V);
    dfs(0, visited, adj, ans);
    return ans;
}

void makeAdj()
{
    // Adjacency List
    for(int i=0; i<5; i++)
    {
        adj[edge[i][0]].push_back(edge[i][1]);
        adj[edge[i][1]].push_back(edge[i][0]);
    }
}

void makeAdjM()
{
    // Adjacency Matrix
    for(int i=0; i<5; i++)
    {
        mat[edge[i][0]][edge[i][1]] = 1;
        mat[edge[i][1]][edge[i][0]] = 1;
    }
}

void printAdj()
{
    cout << "Adjacency List" << endl;
    for(int i=0; i<4; i++)
    {
        for(int j=0; j<adj[i].size(); j++)
        {
            cout << adj[i][j] << " ";            
        }
        cout << endl;
    }
}

void printAdjM()
{
    cout << "Adjacency Matrix" << endl;
    for(int i=0; i<4; i++)
    {
        for(int j=0; j<4; j++)
        {
            cout << mat[i][j] << " ";            
        }
        cout << endl;
    }
}

int main()
{
    makeAdj();
    makeAdjM();

    printAdj();
    printAdjM();

    vector<int> ans;
    ans = dfsOfGraph(vertices, adj);
    cout << "DFS of a Graph" << endl;
    for(int i=0; i<ans.size(); i++)
    {
        cout << ans[i] << " ";
    }
    cout << endl;
    return 0;
}
