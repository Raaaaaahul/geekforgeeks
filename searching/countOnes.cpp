#include<bits/stdc++.h>
using namespace std;
int countOnes(vector<int>& v,int n)
{
    int low = 0;
    int high = n-1;
    while(low<=high)
    {
        int mid = (low+high)/2;
        if(v[mid]==0)
        {
            low = mid+1;
        }
        else
        {
            if(mid==0 or v[mid-1]!=v[mid])
            {
                return n-mid;
            }
            else
            {
                high = mid-1;
            }
        }
    }
    return 0;
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
    int ans = countOnes(v,size);
    cout<<ans;
    return 0;
}