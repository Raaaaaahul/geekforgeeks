#include<bits/stdc++.h>
using namespace std;
int partition(int *arr,int s,int e)
{
    int cnt=0;
    int pivot = arr[s];
    for(int i=s+1;i<=e;i++)
    {
        if(arr[i]<=pivot){
            cnt++;
        }
    }
    int pivotIdx = s + cnt;
    swap(arr[s],arr[pivotIdx]);

    int i = s,j=e;
    while(i<pivotIdx and j>pivotIdx)
    {
        while(arr[i]<=pivot)
        {
            i++;
        }
        while(arr[j]>pivot)
        {
            j--;
        }
        if(i<pivotIdx and j>pivotIdx)
        {
            swap(arr[i++],arr[j--]);
        }
    }
    return pivotIdx;

}
void quickSort(int *arr,int s,int e)
{
    if(s>=e)
        return;
    
    int idx = partition(arr,s,e);
    quickSort(arr,s,idx-1);
    quickSort(arr,idx+1,e);
}
int main()
{
    int arr[10] = {5,7,69,63,42,28,9,11,17,28};
    quickSort(arr,0,9);
    for(int i=0;i<10;i++)   
    {
        cout<<arr[i]<<" ";
    }
    return 0;
}