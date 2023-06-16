#include<bits/stdc++.h>
using namespace std;
bool isPair(vector<int>& v,int n,int x)
{
    int l=0,r=n-1;
    while(l<r)
    {
        if(v[l] + v[r] == x)
        {
            return true;
        }
        else if(v[l] + v[r] < x)
        {
            l++;
        }
        else
        {
            r--;
        }
    }
    return false;
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
    int ans = isPair(v,n,12);
    cout<<ans;
    return 0;
}