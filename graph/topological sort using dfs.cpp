#include<bits/stdc++.h>
using namespace std;

void dfs(vector<vector<int>>& g,vector<bool>& vis,stack<int>& st,int src)
{
    vis[src] = true;
    for(int nbr : g[src])
    {
        if(vis[nbr]==false)
        {
            dfs(g,vis,st,nbr);
        }
    }
    st.push(src);
}

vector<int> topologicalSort(vector<vector<int>>& g,int v)
{
    vector<bool> vis(v,false);
    stack<int> st;
    vector<int> ans;
    for(int i=0;i<v;i++)
    {
        if(vis[i]==false)
        {
            dfs(g,vis,st,i);
        }
    }
    while(!st.empty())
    {
        ans.push_back(st.top());
        st.pop();
    }
    return ans;
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
    vector<int> ans = topologicalSort(g,n);
    for(auto it:ans)
    {
        cout<<it<<" ";
    }
    return 0;
}