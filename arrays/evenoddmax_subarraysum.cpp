#include<bits/stdc++.h>
using namespace std;
int solve1(vector<int>& v,int size)
{
    int res = 1;
    for(int i=0;i<size;i++)
    {
        int curr = 1;
        for(int j = i+1;j<size;j++)
        {
            if((v[j]%2==0 and v[j-1]%2!=0) || (v[j]%2!=0 and v[j-1]%2==0))
            {
                curr++;
            }
            else
                break;
            
            res = max(res,curr);
        }
    }
    return res;
}

int solve2(vector<int>& v,int size)
{
    int res = 1,curr = 1;
    for(int i=0;i<size;i++)
    {
        if((v[i]%2==0 and v[i-1]%2!=0) || (v[i]%2!=0 and v[i-1]%2==0))
        {
            curr++;
            res = max(res,curr);
        }
        else
            curr = 1;
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
    cout<<solve1(v,size);
    return 0;
}