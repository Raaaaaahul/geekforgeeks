#include<bits/stdc++.h>
using namespace std;
bool solve(int *arr,int size)
{
    bool ans = true;
    for(int i=0;i<size-1;i++)
    {
        if(arr[i]>arr[i+1])
        {
            ans = false;break;
        }
    }
    return ans;
}
int main()
{
    int size;
    cin>>size;
    int arr[size];
    for(int i=0;i<size;i++)
    {
        cin>>arr[i];
    }
    int ans = solve(arr,size);
    cout<<ans;
    return 0;
}