#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    vector<int> v(n);
    for(int i=0;i<n;i++)
    {
        cin>>v[i];
    }
    long long sum = 0;
    int mx = v[n-1];
    sort(v.begin(),v.end());
    for(int i=0;i<n;i++)
    {
        sum += (i+1)*v[i] + mx;
    }
    cout<<sum;
    return 0;
}