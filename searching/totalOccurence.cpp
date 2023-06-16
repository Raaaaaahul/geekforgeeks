#include<bits/stdc++.h>
using namespace std;
int firstOccur(vector<int>& v,int n,int ele)
{
    int low = 0;
    int high = n-1;
    while(low<=high)
    {
        int mid = (low+high)/2;
        if(v[mid]>ele)
        {
            high = mid-1;
        }
        else if(v[mid]<ele)
        {
            low = mid +1;
        }
        else
        {
            if(mid==0 or v[mid-1]!=v[mid])
            {
                return mid;
            }
            else
            {
                high = mid - 1;
            }
        }
    }
    return -1;
}
int lastOccur(vector<int>& v,int n,int ele)
{
    int low = 0;
    int high = n-1;
    while(low<=high)
    {
        int mid = (low+high)/2;
        if(v[mid]>ele)
        {
            high = mid-1;
        }
        else if(v[mid]<ele)
        {
            low = mid+1;
        }
        else
        {
            if(mid==n-1 or v[mid]!=v[mid+1])
            {
                return mid;
            }
            else
            {
                low = mid+1;
            }
        }
    }
    return -1;
}
int totOccur(vector<int>& v,int n,int ele)
{
    int first = firstOccur(v,n,ele);
    if(first==-1)
        return 0;
    else
        return (lastOccur(v,n,ele) - first + 1);
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
    int ans = totOccur(v,size,5);
    cout<<ans;
    return 0;
}