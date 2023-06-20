#include<bits/stdc++.h>
using namespace std;
bool solve(vector<int>& v,int n,int sum)
{
    unordered_set<int> s;
    int preSum = 0;
    for(int i=0;i<n;i++)
    {
        if(preSum==sum)
        {
            return true;
        }
        if(s.find(preSum-sum)!=s.end())
            return true;
        s.insert(preSum);
    }
    return false;
}
int main()
{
    int n;
    cin>>n;
    vector<int> v(n);
    for(int i=0;i<n;i++)
    {
        cin>>v[i];
    }
    cout<<solve(v,n,22);
    return 0;
}