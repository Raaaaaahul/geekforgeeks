#include<bits/stdc++.h>
using namespace std;
void solve(vector<int>& v,int size)
{
    for(int i=0;i<size;i++)
    {
        bool flag = false;
        for(int j = i+1;j<size;j++)
        {
            if(v[i]<=v[j])
            {
                flag = true;
                break;
            }
        }
        if(flag==false)
        {
            cout<<v[i]<<" ";
        }
    }

}
void solve1(vector<int>& v,int size)
{
    int crr_leader = v[size-1];
    cout<<crr_leader<<" ";
    for(int i = size-2;i>=0;i--)
    {
       if(crr_leader<v[i])
       {
        crr_leader = v[i];
        cout<<crr_leader<<" ";
       } 
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