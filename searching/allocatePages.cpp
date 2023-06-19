#include<bits/stdc++.h>
using namespace std;
int solvee(vector<int>&v ,int n,int k)
{
    
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
    cout<<"students\n";
    int k;
    cin>>k;
    cout<<solvee(v,n,k);
    return 0;
}