#include<bits/stdc++.h>
using namespace std;
int peakEle(vector<int>& v,int n)
{
    int low = 0, high = n-1;
    while(low<=high)
    {
        int mid = (low+high)/2;
        if((mid==0 or v[mid]>=v[mid-1]) and (mid==n-1 or v[mid]>=v[mid+1]))
        {
            return mid;
        }
        if(mid>0 and v[mid-1]>v[mid])
        {
            high = mid -1;
        }
        else
        {
            low = mid +1;
        }
    }
    return -1;
}
int main()
{
    int n;
    cin>>n;
    vector<int> v(n);
    for(int i=0;i<n;i++)
    {
        cin>>v[i];
    }
    int ans = peakEle(v,n);
    cout<<ans;
    return 0;
}