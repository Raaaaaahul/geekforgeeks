#include<bits/stdc++.h>
using namespace std;
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
int main()
{
    int size;
    cin>>size;
    vector<int> v(size);
    for(int i=0;i<size;i++)
    {
        cin>>v[i];
    }
    int ans = lastOccur(v,size,5);
    cout<<ans;
    return 0;
}