#include<bits/stdc++.h>
using namespace std;
int soRotated(vector<int>& v,int n,int ele)
{
    int low = 0,high = n-1;
    while(low<=high)
    {
        int mid = (low+high)/2;
        if(v[mid]==ele) return mid;
        
        if(v[low]<v[mid])
        {
            if(ele>=v[low] && ele<v[mid])
                high = mid -1;
            else
                low = mid +1;
        }
        else
        {
            if(ele>v[mid] && ele<=v[high])
                low = mid+1;
            else
                high = mid-1;
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
    int ans = soRotated(v,n,5);
    cout<<ans;
    return 0;
}