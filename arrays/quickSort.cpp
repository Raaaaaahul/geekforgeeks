#include<bits/stdc++.h>
using namespace std;
int answer = 0;
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
    answer++;

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
            answer++;
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
    int arr[4] = {2,8,5,4};
    quickSort(arr,0,3);
    for(int i=0;i<4;i++)   
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl<<answer;
    return 0;
}