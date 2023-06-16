#include<bits/stdc++.h>
using namespace std;
int solve(vector<int>& v,int size)
{
    vector<int> temp(size);
    temp[0] = v[0];
    int res = 1;
    for(int i=1;i<size;i++)
    {
        if(temp[res-1]!=v[i])
        {
            temp[res] = v[i];
            res++;
        }
    }
    for(int i=0;i<res;i++)
    {
        v[i] = temp[i];
    }

    return res;
}
int solve2(vector<int> &v,int size)
{
    int res = 1;
    for(int i=1;i<size;i++)
    {
        if(v[res-1]!=v[i])
        {
            v[res] = v[i];
            res++;
        }
    }
    return res;
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
    cout<<solve2(v,size);
    return 0;
}