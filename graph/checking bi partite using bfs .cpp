#include<bits/stdc++.h>
using namespace std;
bool bfs(vector<vector<int>>& g,vector<int>& color,int start)
{
    queue<int> q;
    color[start] = 0;
    q.push(start);
    while(!q.empty())
    {
        int src = q.front();
        q.pop();
        for(auto nbr : g[src])
        {
            if(color[nbr]==-1)
            {
                color[nbr]=!color[src];
                q.push(nbr);
            }
            else if(color[nbr]==color[src])
            {
                return false;
            }
        }
    }
    return true;
}
bool solve(vector<vector<int>>& g)
{
    int n = g.size();
    vector<int> color(n,-1);
    for(int i=0;i<n;i++)
    {
        if(color[i]==-1)
        {
            if(!bfs(g,color,i))
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