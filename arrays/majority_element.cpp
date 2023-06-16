#include<bits/stdc++.h>
using namespace std;
int solve(vector<int>& v,int n)
{
    int ans = -1;
    unordered_map<int,int> mp;
    for(int i=0;i<n;i++)
    {
        mp[v[i]]++;
        if(mp[v[i]]>n/2)
        {
            ans = v[i];
        }
    }
    return ans;
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
    cout<<solve(v,size);
    return 0;
}