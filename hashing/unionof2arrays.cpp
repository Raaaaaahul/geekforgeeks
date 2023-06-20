#include<bits/stdc++.h>
using namespace std;
void solve(vector<int>& v1,vector<int>& v2,int size1,int size2)
{
    unordered_set<int> s;
    for(int i=0;i<size1;i++)
    {
        s.insert(v1[i]);
    }
    for(int j=0;j<size2;j++)
    {
        s.insert(v2[j]);
    }
    for(auto it: s)
    {
        cout<<it<<" ";
    }
}
int main()
{
    int size1,size2;
    cin>>size1>>size2;
    vector<int> v1(size1);
    vector<int> v2(size2);
    for(int i=0;i<size1;i++)
    {
        cin>>v1[i];
    }
    for(int i=0;i<size2;i++)
    {
        cin>>v2[i];
    }
    solve(v1,v2,size1,size2);
    return 0;
}