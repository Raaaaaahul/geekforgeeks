#include<bits/stdc++.h>
using namespace std;
int solve(vector<int>& arr,int n)
{
    int res = arr[0];
    int prev_sum = arr[0];
    for(int i=1;i<n;i++)
    {
        prev_sum = max(prev_sum+arr[i],arr[i]);
        res = max(res,prev_sum);
    }
    return res; 
}
int main()
{
    int size;
    cin>>size;
    vector<int> arr(size);
    for(int i=0;i<size;i++)
    {
        cin>>arr[i];
    }
    cout<<solve(arr,size);
    return 0;
}