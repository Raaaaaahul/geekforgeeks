#include<bits/stdc++.h>
using namespace std;
void solve(vector<int>& v,int size)
{
    unordered_map<int,int> mp;
    for(int i=0;i<size;i++)
    {
        mp[v[i]]++;
    }
    for(auto it: mp)
    {
        if(it.second>=size/3)
        {
            cout<<it.first<<endl;
        }
    }
}
int main()
{
    int size;
    cin>>size;
    vector<int> v(size);
    for (int i=0;i<size;i++){
        cin>>v[i];
    }
    solve(v,size);
    return 0;
}