#include<bits/stdc++.h>
using namespace std;
int Distinct(vector<int>& v,int size)
{
    unordered_set<int> s;
    for(int i=0;i<size;i++)
    {
        s.insert(v[i]);
    }
    return s.size();
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
    int ans = Distinct(v,size);
    cout<<ans;
    return 0;
}