#include<bits/stdc++.h>
using namespace std;
void merge(vector<int>& v,int l,int m,int r)
{
    //length of arrays
    int len1 = m-l+1;
    int len2 = r-m;
    
    //make arrays of len1 and len2
    int *first = new int[len1];
    int *second = new int[len2];

    //make a main idx for the orignal array
    int mainIdx = l;
    //make copy of elements in the first and second array
    for(int i=0;i<len1;i++)
    {
        first[i] = v[mainIdx++];
    }
    mainIdx = m+1;
    for(int i=0;i<len2;i++)
    {
        second[i] = v[mainIdx++];
    }
    //merging the arrays on the basis of the element which are smaller using the first and second
    int idx1 = 0,idx2=0;
    mainIdx = l;
    while(idx1<len1 and idx2<len2)
    {
        if(first[idx1]<second[idx2])
        {
            v[mainIdx++] = first[idx1++];
        }
        else 
        {
            v[mainIdx++] = second[idx2++];
        }
    }
    // merging remaining elements
    while(idx1<len1)
    {
        v[mainIdx++]=first[idx1++];
    }
    while(idx2<len2)
    {
        v[mainIdx++] = second[idx2++];
    }
    delete []first;
    delete []second;

}
void mergeSort(vector<int>& v,int l,int r)
{
    if(l>=r)
    {
        return;
    }
    int m = l + (r-l)/2;
    mergeSort(v,l,m);
    mergeSort(v,m+1,r);
    merge(v,l,m,r);
}
int main()
{
    vector<int> v{2,35,5,2,15,5};
    int l = 0;
    int r = v.size()-1;
    mergeSort(v,l,r);
    for(auto it:v)
    {
        cout<<it<<" ";
    }
    return 0;
}