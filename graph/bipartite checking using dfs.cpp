#include<bits/stdc++.h>
using namespace std;
bool dfs(vector<vector<int>>& g,vector<int>& visited,int src,int color)
{
    visited[src] = color;
    for(auto nbr : g[src])
    {
        if(visited[nbr]==-1)
        {
            if(dfs(g,visited,nbr,!color)==false)
            {
                return false;
            }
        }
        // if already visited and color matches with the adjacent node then =>
        else if(visited[nbr] == color)
        {
            return false;
        }
    }
    return true;
}
bool solve(vector<vector<int>>& g)
{
    int n = g.size();
    vector<int> visited(n,-1);
    for(int i=0;i<n;i++)
    {
       if(visited[i]==-1)
       {
            if(dfs(g,visited,i,0)==false)
            {
                return false;
            }
       }
    }
    return true;
}

int main()
{
    int n=4;
    vector<vector<int>> g(n);
    g = {{1,3},{0,2},{1,3},{0,2}};
    cout<<solve(g);
    return 0;
}