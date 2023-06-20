#include<bits/stdc++.h>
using namespace std;
void solve(vector<int>& v,int n)
{
    unordered_map<int,int> mp;
    for(int i=0;i<n;i++)
    {
        mp[v[i]]++;
    }
    for(auto it:mp)
    {
        cout<<it.first<<" "<<it.second<<endl;
    }
}
int main()
{
    int size;
    cin>>size;
    vector<int> v(size);
    for(int i=0;i<size;i++)
    {
        cin>>v[i];
    }
    solve(v,size);
    return 0;
}