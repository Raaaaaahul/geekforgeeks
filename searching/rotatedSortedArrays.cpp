#include<bits/stdc++.h>
using namespace std;

int solve(vector<int>& v,int l,int h,int key)
{
    if(l>h)
    {
        return -1;
    }
    int mid = (l+h)/2;
    if(v[mid]==key)
    {
        return mid;
    }
    //left part is sorted
    if(v[l]<v[mid])
    {
        if(key>=v[l] and key<=v[mid])
        {
            return solve(v,l,mid,key);
        }
        else
        {
            return solve(v,mid+1,h,key);
        }
    }
    else
    {
        if(key>=v[mid] and key<=v[h])
        {
            return solve(v,mid+1,h,key);
        }
        else
        {
            return solve(v,l,mid-1,key);
        }
    }
}

int main()
{
    vector<int> v{5, 6, 7, 8, 9, 10, 1, 2, 3};
    int key = 10;
    int l=0;
    int h=8;
    int ans = solve(v,l,h,key);
    cout<<ans;
    return 0;
}