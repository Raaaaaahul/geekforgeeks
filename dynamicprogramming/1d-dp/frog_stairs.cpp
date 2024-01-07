#include<bits/stdc++.h>
using namespace std;

int min_energy(int idx,vector<int>& ht,vector<int>& dp)
{
    if(idx==0)
    {
        return 0;
    }

    if(dp[idx]!=-1)
    {
        return dp[idx];
    }

    // int jump1 = INT_MAX;
    int jump2 = 1e9;
    int jump1 = abs(ht[idx] - ht[idx-1]) + min_energy(idx-1,ht,dp);
    if(idx>1) 
    {
        jump2 = abs(ht[idx] - ht[idx-2]) + min_energy(idx-2,ht,dp);
    }
    return dp[idx] = min(jump1,jump2);
    
}

int main()
{
    vector<int> ht{30,10,60 , 10 , 60 , 50};
    int n = ht.size();
    vector<int> dp(n,-1);
    int ans = min_energy(n-1,ht,dp);
    cout<<ans;
    return 0;
}