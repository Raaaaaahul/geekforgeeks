#include<bits/stdc++.h>
using namespace std;
void solve(vector<int>& v,int size)
{
    int res = v[1] - v[0];
    for(int i=0;i<size-1;i++)
    {
        for(int j=i+1;j<size;j++)
        {
            res = max(res,v[j] - v[i]);
        }
    }
    cout<<res;
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
    solve(v,size);
    return 0;
}