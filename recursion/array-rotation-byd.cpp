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
void reverse(int *arr,int low,int high)
{
    while(low<high)
    {
        swap(arr[low],arr[high]);
        low++;
        high--;
    }
}
void rotbyd(int *arr,int d,int size)
{
    reverse(arr,0,d-1);
    reverse(arr,d,size-1);
    reverse(arr,0,size-1);
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
    rotbyd(arr,d,size);
    disp(arr,size);
    return 0;
}