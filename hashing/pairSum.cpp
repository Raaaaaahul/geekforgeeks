#include<bits/stdc++.h>
using namespace std;
void solve(vector<int>& v,int n,int sum)
{
    unordered_set<int> s;
    for(int i=0;i<n;i++)
    {
        if(s.find(sum - v[i])!=s.end())
        {
            cout<<"pair exists"<<endl;
        }
        s.insert(v[i]);
    }
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
    solve(v,n,10);
    return 0;
}