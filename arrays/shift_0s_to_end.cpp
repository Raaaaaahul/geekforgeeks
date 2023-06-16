#include<bits/stdc++.h>
using namespace std;
void solve(vector<int>& v,int size)
{
    int j = 0;
    for(int i=0;i<size;i++)
    {
        if(v[i]!=0)
        {
            swap(v[i],v[j]);
            j++;
        }
    }
    for(int i=0;i<size;i++)
    {
        cout<<v[i]<<" ";
    }
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