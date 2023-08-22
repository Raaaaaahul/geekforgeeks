#include<bits/stdc++.h>
using namespace std;
void solve(vector<int>& arr,vector<int>& ds,int n,int idx)
{
    if(idx==n)
    {
        for(auto it:ds)
        {
            cout<<it<<" ";
        }
        cout<<endl;
        return;
    }
    ds.push_back(arr[idx]);
    solve(arr,ds,n,idx+1);
    ds.pop_back();
    solve(arr,ds,n,idx+1);
}
int main()
{
    vector<int> arr{3,1,2};
    int n = arr.size();
    vector<int> ds;
    solve(arr,ds,n,0);
    return 0;
}