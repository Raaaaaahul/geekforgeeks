#include<bits/stdc++.h>
using namespace std;
void solve(vector<int>& arr,int n)
{
    int low = 0;
    int mid = 0;
    int high = n-1;

    while(mid<=high)
    {
        if(arr[mid]==0)
        {
            swap(arr[low],arr[mid]);
            low++;
            mid++;
        }
        else if(arr[mid]==1)
        {
            mid++;
        }
        else
        {
            swap(arr[mid],arr[high]);
            high--;
        }
    }
}
int main()
{
    vector<int> arr{0,2,1,2,0};
    int n = arr.size();
    solve(arr,n);
    for(auto it:arr)
    {
        cout<<it<<" ";
    }
    return 0;
}