#include<bits/stdc++.h>
using namespace std;
void toplogicalSort(vector<vector<int>>& g,vector<int>& indeg)
{
    queue<int> q;
    for(int i=0;i<indeg.size();i++)
    {
        if(indeg[i]==0)
        {
            q.push(i);
        }
    }
    while(q.empty()==false)
    {
        int u = q.front();
        q.pop();
        cout<<u<<" ";
        for(int nbr : g[u])
        {
            indeg[nbr]--;
            if(indeg[nbr]==0)
            {
                q.push(nbr);
            }
        }
    }
}
int main()
{
    int n,m;
    cin>>n>>m;
    vector<vector<int>> g(n);
    vector<int> indeg(n,0);
    for(int i=0;i<m;i++)
    {
        int u,v;
        cin>>u>>v;
        g[u].push_back(v);
        indeg[v]++;
    }
    toplogicalSort(g,indeg);
    return 0;
}