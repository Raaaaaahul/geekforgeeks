#include<bits/stdc++.h>
using namespace std;
void disp(int *arr,int size)
{
    for(int i=0;i<size;i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}
void left(int arr[],int n,int d)
{
    reverse(arr,0,d-1);
    reverse(arr,d,n-1);
    reverse(arr,0,n-1);
}
int main()
{
    int size,d;
    cin>>size;
    cin>>d;
    int arr[size];
    for(int i=0;i<size;i++)
    {
        cin>>arr[i];
    }
    disp(arr,size);
    while(d--)
    {
        int temp = arr[0];
        for(int i=0;i<size;i++)
        {    
            arr[i] = arr[i+1];
        }
        arr[size-1] = temp;
    }
    
    disp(arr,size);
    return 0;
}