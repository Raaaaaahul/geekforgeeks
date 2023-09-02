#include<bits/stdc++.h>
using namespace std;
int solve(int n,vector<int>& vec)
{
    unordered_map<int,int> mp;
    int sum = 0;
    int max_len = 0;
    for(int i=0;i<n;i++)
    {
        sum+=vec[i];
        
        if(sum==0)
        {
            max_len = i+1;
        }
        if(mp.find(sum)!=mp.end())
        {
            max_len = max(max_len,i-mp[sum]);
        }
        else
            mp[sum]=i;
    }
    return max_len;
}
int main()
{
    vector<int> vec{15,-2,2,-8,1,7,10,23};
    int n = vec.size();
    cout<<solve(n,vec);
    return 0;
}