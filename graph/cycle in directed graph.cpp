#include<bits/stdc++.h>
using namespace std;

bool dfs(vector<vector<int>>& g,vector<bool>& vis,vector<bool>& stRec,int src)
{
    vis[src] = true;
    stRec[src] = true;

    for(int nbr : g[src])
    {
        if(vis[nbr]==false)
        {
            if(dfs(g,vis,stRec,nbr))
            {
                return true;
            }
        }
        else if(stRec[nbr]==true)
        {
            return true;
        }
    }
    stRec[src]=false;
    return false;
}

bool cycle(vector<vector<int>>& g,int n)
{
    vector<bool> vis(n,false);
    vector<bool> stRec(n,false);
    
    for(int i=0;i<n;i++)
    {
        if(vis[i]==false)
        {
            if(dfs(g,vis,stRec,i))
            {
                return true;
            }
        }
    }
    return false;
}
int main()
{
    int n,m;
    cin>>n>>m;
    vector<vector<int>> g(n);
    for(int i=0;i<m;i++)
    {
        int u,v;
        cin>>u>>v;
        g[u].push_back(v);
    }
    bool ans = cycle(g,n);
    cout<<endl<<ans;
    return 0;
}