#include<bits/stdc++.h>
using namespace std;
bool solve(vector<int>& v,int n)
{
    unordered_set<int> s;
    int preSum = 0;
    for(int i=0;i<n;i++)
    {
        preSum+=v[i];
        if(s.find(preSum)!=s.end())
            return true;
        if(preSum==0) //0 ke jgh sum wala variable for a given sum
            return true;
        s.insert(preSum);
    }
    return false;
}
int main()
{
    int n;
    cin>>n;
    vector<int>v(n);
    for (auto &i : v){
        cin>>i;
    }
    cout<<solve(v,n);
    return 0;
}