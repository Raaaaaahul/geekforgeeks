#include<bits/stdc++.h>
using namespace std;

vector<int> solve(vector<int>& v,int n ,int k)
{
    unordered_map<int,int> mp;
    vector<int> ans;
    for(int i=0;i<k;i++)
    {
        mp[v[i]]++;
    }
    ans.push_back(mp.size());
    int j=0; // previous window ka start index
    for(int i=k;i<n;i++)
    {
        mp[v[j]]--;
        if(mp[v[j]]<=0)
        {
            mp.erase(v[j]);
        }
        mp[v[i]]++;
        ans.push_back(mp.size());
    }
    return ans;
}

int main()
{
    vector<int> v{1,2,1,3,4,2,3};
    int n = v.size();
    int k = 4;
    vector<int> ans = solve(v,n,k);
    for(auto it:ans)
    {
        cout<<it<<" ";
    }
    return 0;
}