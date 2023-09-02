#include<bits/stdc++.h>
using namespace std;
int solve(int n,vector<int>& vec)
{
    unordered_map<int,int> mp;
    for(int i=0;i<vec.size();i++)
    {
        mp[vec[i]]++;
    }
    for(int i=1;i<=n;i++)
    {
        if(mp.find(i)==mp.end())
        {
            return i;
        }
    }
    return -1;
}
int solve1(int n,vector<int>& vec)
{
    int sum = (n*(n+1))/2;
    int temp = accumulate(vec.begin(),vec.end(),0);
    return abs(sum - temp);
}
int main()
{
    int N=10;
    vector<int> vec{6,1,2,8,3,4,7,10,5};
    cout<<solve(N,vec);
    return 0;
}