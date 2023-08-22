#include<bits/stdc++.h>
using namespace std;
void solve(int idx,int s,int n,int k,vector<int>& arr,vector<int>& v)
{
    if(idx==n)
    {
        if(s==k)
        {
            for(auto it:v)
            {
                cout<<it<<" ";
            }
            cout<<endl;
        }
        return;
    }
    //include
    s+=arr[idx];
    v.push_back(arr[idx]);
    solve(idx+1,s,n,k,arr,v);
    s-=arr[idx];
    v.pop_back();
    solve(idx+1,s,n,k,arr,v);
}
int main()
{
    vector<int> arr{1,2,6,4,3,3};
    int n = arr.size();
    int k=6;
    vector<int> v;
    solve(0,0,n,k,arr,v);
    return 0;
}