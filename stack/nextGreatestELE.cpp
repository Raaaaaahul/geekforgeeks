#include<bits/stdc++.h>
using namespace std;
void solve(vector<int>& v,int n)
{
    for(int i=0;i<n;i++)
    {
        int j;
        for(j = i+1;j<n;j++)
        {
            if(v[j]>v[i])
            {
                cout<<v[j]<<" ";break;
            }
        }
        if(j==n)
        {
            cout<<"-1 ";
        }
    }
}
void solvEff(vector<int>& v,int n)
{
    stack<int> s;
    vector<int> res;
    s.push(v[n-1]);
    res.push_back(-1);
    for(int i=n-2;i>=0;i--)
    {
        while(s.empty()==false and s.top()<=v[i])
        {
            s.pop();
        }
        int nextGr = s.empty()?-1:s.top();
        res.push_back(nextGr);
    }
    reverse(res.begin(),res.end());
    for(int i=0;i<res.size();i++)
    {
        cout<<res[i]<<" ";
    }
}
int main()
{
    int size;
    cin >>size;
    vector<int> v(size);
    for(int i=0;i<size;i++)
    {
        cin>>v[i];
    }
    solvEff(v,size);
    return 0;
}