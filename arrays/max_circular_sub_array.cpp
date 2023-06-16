#include<bits/stdc++.h>
using namespace std;
int kadane(vector<int>& v,int size)
{
    int res = v[0];
    int curr_sum = v[0];
    for(int i=1;i<size;i++)
    {
        curr_sum = max(curr_sum + v[i],v[i]);
        res = max(res,curr_sum);
    }
    return res; 
}
int solve(vector<int>& v,int n)
{
    int max_normal = kadane(v,n);
    if(max_normal<0)
    {
        return max_normal;
    }

    int sum = 0;
    for(int i=0;i<n;i++)
    {
        sum+=v[i];
        v[i] = -v[i];
    }
    int max_circular = sum + kadane(v,n);
    return max(max_normal,max_circular);
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
    cout<<solve(v,size);
    return 0;
}