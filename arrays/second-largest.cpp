#include<bits/stdc++.h>
using namespace std;
int solve(int *arr,int size)
{
    int res = -1,largest = 0;
    for(int i=1;i<size;i++)
    {
        if(arr[i]>arr[largest])
        {
            res = largest;
            largest = i;
        }
        else if(arr[i]!=arr[largest])
        {
            if(res==-1 or arr[i]>arr[res])
            {
                res = i;
            }
        }
    }
    return res+1;
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