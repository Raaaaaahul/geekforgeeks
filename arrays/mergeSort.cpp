#include<bits/stdc++.h>
using namespace std;
void merge(vector<int>& v,int s,int e)
{
    int mid = (s+e)/2;
    int len1 = mid-s+1;
    int len2 = e-mid;

    vector<int> first(len1);
    vector<int> second(len2);

    int vecIdx = s;
    for(int i=0;i<len1;i++)
    {
        first[i]=v[vecIdx++];
    }
    vecIdx = mid+1;
    for(int i=0;i<len2;i++)
    {
        second[i] = v[vecIdx++];
    }
    int idx1 = 0;
    int idx2 = 0;
    vecIdx = s;
    while(idx1<len1 && idx2<len2)
    {
        if(first[idx1] < second[idx2])
        {
            v[vecIdx++] = first[idx1++];
        }
        else
        {
            v[vecIdx++] = second[idx2++];
        }
    }
    while(idx1<len1)
    {
        v[vecIdx++] = first[idx1++];
    }
    while(idx2<len2)
    {
        v[vecIdx++] = second[idx2++];
    }
}
void mergeSort(vector<int>& v,int s,int e)
{
    //base case
    if(s>=e)
    {
        return;
    }
    int mid = (s+e)/2;
    //sorting left sub array
    mergeSort(v,s,mid);
    //sorting right sub array
    mergeSort(v,mid+1,e);
    //merge sorted arrays
    merge(v,s,e);
}
int main()
{
    int size;
    cin>>size;
    vector<int> v(size);
    for(int i=0;i<size;i++)
    {
        cin>>v[i];
    }
    cout<<endl;
    mergeSort(v,0,size-1);
    for(int i=0;i<size;i++)
    {
        cout<<v[i]<<" ";
    }

    return 0;
}