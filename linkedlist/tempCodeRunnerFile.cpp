#include<bits/stdc++.h> 
using namespace std;

bool trio(int i,int j,int k,vector<vector<bool>>& vis)
{
    if(vis[i][j]==false or vis[j][i]==false)
    {
        return false;
    }
    if(vis[j][k]==false or vis[k][j]==false)
    {
        return false;
    }
    if(vis[i][k]==false or vis[k][i]==false)
    {
        return false;
    }
    return true;
}


int solve(int n,vector<vector<int>>& edges)
{
    vector<vector<bool>> vis(n+1,vector<bool>(n+1,false));
    vector<int> degree(n+1,0);
    vector<vector<int>> g(n+1);
    for(int i=0;i<edges.size();i++)
    {
        int u = edges[i][0];
        int v = edges[i][1];
        vis[u][v] = true;
        vis[v][u] = true;
        degree[u]++;
        degree[v]++;
    }
    int result = 1e9;
    for(int i=1;i<=n-2;i++)
    {
        for(int j=1;j<=n-1;j++)
        {
            for(int k = 1;k<=n;k++)
            {
                if(trio(i,j,k,vis))
                {
                    int count = 0;
                    count += degree[i]-2;
                    count += degree[j]-2;
                    count += degree[k]-2;
                    result = min(result,count);
                }
            }
        }
    }
    return result==1e9?-1:result;
}


int main()
{
    int n = 6;
    vector<vector<int>> edges = {{1,2},{1,3},{3,2},{4,1},{5,2},{3,6}};
    int ans = solve(n,edges);
    return 0;
}