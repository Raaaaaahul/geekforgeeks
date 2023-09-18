#include<bits/stdc++.h>
using namespace std;

int bfs(vector<vector<int>>& g,vector<bool>& vis,int src)
{
    vis[src] = true;
    queue<int> q;
    q.push(src);
    int count = 1;
    while(q.empty()==false)
    {
        int node = q.front();
        q.pop();
        for(int nbr : g[node])
        {
            if(vis[nbr]==false)
            {
                vis[nbr] = true;
                q.push(nbr);
                count++;
            }
        }
    }
    return count;
}
int solve(int n,vector<int>& from,vector<int>& to)
{
    vector<vector<int>> g(n);
    for(int i=0;i<from.size();i++)
    {
        int u = from[i];
        int v = to[i];
        g[u].push_back(v);
        g[v].push_back(u);
    }

    vector<int> ans;
    vector<bool> vis(n,false);
    for(int i=0;i<n;i++)
    {
        if(vis[i]==false)
        {
            int temp = bfs(g,vis,i);
            ans.push_back(temp);
        }
    }
    int sum = 0;
    for(int x:ans)
    {
        sum+= ceil(sqrt(x));
    }
    return sum;
}
int main()
{
    int n=10;
    vector<int> from{1,1,2,3,7};
    vector<int> to{2,3,4,5,8};
    cout<<solve(n,from,to);
    return 0;
}