#include<bits/stdc++.h>
using namespace std;
int solve(int idx,int s,vector<int>& arr,int n,int k)
{
    if(s>k)
        return 0;
    if(idx==n)
    {
        if(s==k)
            return 1;
        else
            return 0;
    }

    s+=arr[idx];
    int l = solve(idx+1,s,arr,n,k);
    s-=arr[idx];
    int r = solve(idx+1,s,arr,n,k);
    return l+r;
}
int main()
{
    vector<int> arr{1,2,6,4,3,3};
    int n = arr.size();
    int k=6;
    cout<<solve(0,0,arr,n,k);
    return 0;
}