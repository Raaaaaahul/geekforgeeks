#include<bits/stdc++.h>
using namespace std;
int solvee(vector<int> v,int n)
{
    int slow = v[0] + 1 , fast = v[0] + 1;
    do{
        slow = v[slow]+1;
        fast = v[v[fast]+1]+1;
    }while(slow!=fast);
    slow = v[0]+1;
    while(slow!=fast)
    {
        fast = v[fast]+1;
        slow = v[slow]+1;
    }
    return slow-1;
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
    cout<<solvee(v,n);
    return 0;
}