#include<bits/stdc++.h>
using namespace std;
int solve(vector<int>& v,int sum)
{
    int currSum = 0;
    int res = 0;
    unordered_map<int,int> mp;
    for(int i=0;i<v.size();i++)
    {
        currSum+=v[i];
        if(currSum==sum)
        {
            res++;
        }

        if(mp.find(currSum-sum)!=mp.end())
        {
            res+=mp[currSum-sum];
        }
        mp[currSum]++;
    }
    return res;
}
int main()
{
    vector<int> v{0,0,5,5,0,0};
    int sum = 0;
    cout<<solve(v,sum);
    return 0;
}