#include<bits/stdc++.h>
using namespace std;
void solve(vector<int>& v,int n)
{
    int i,j;
    int maxi = v[n-1]+1;
    j = n-1;
    //even position
    for(int i=0;i<n;i+=2)
    {
        v[i]+= (v[j]%maxi)*maxi;
        j--;
    }
    j=0;
    //odd position
    for(int i=1;i<n;i+=2)
    {
        v[i]+= (v[j]%maxi)*maxi;
        j++;
    }
    for(i=0;i<n;i++)
    {
        v[i]/=maxi;
    }
}
int main()
{
    vector<int> v{1,2,3,4,5,6};
    solve(v,v.size());
    for(auto it:v)
    {
        cout<<it<<" ";
    }
    
    return 0;
}