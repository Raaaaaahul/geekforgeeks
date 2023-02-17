#include<bits/stdc++.h>
using namespace std;
int main()
{
    int size;
    cin>>size;
    int arr[size];
    for(int i=0;i<size;i++)
    {
        cin>>arr[i];
    }
    int max = 0;
    int max_idx = 0;
    for(int i=0;i<size;i++)
    {
        if(arr[i]>max)
        {
            max = arr[i];
            max_idx = i;
        }
    }
    cout<<max<<endl<<max_idx;
    return 0;
}