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