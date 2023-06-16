#include<bits/stdc++.h>
using namespace std;
bool binarySearch(vector<int>& v,int size,int ele)
{
    int low = 0;
    int high = size-1;
    while(low<=high)
    {
        int mid = (low+high)/2;
        if(v[mid]==ele)
        {
            return true;
        }
        else if(v[mid]>ele)
        {
            high = mid -1;
        }
        else
        {
            low = mid+1;
        }
    }
    return false;
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
    int ans = binarySearch(v,size,34);
    cout<<ans;
    return 0;
}