#include<bits/stdc++.h>
using namespace std;
int solve(vector<int>& v,int n)
{
    int ans = 0;
    for(int i=1;i<n;i++)
    {
        if(v[i]>v[i-1])
        {
            ans+=v[i] - v[i-1];
        }
    }
    return ans;
}
int main()
{
    int n = 5;
    vector<int> v(n);
    cout<<"enter the elements"<<endl;
    for(int i=0;i<n;i++)
    {
        cin>>v[i];
    }
    cout<<solve(v,n);
    return 0;
}