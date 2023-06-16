#include<bits/stdc++.h>
using namespace std;
bool checkTrip(vector<int>& v,int n)
{
    for(int i=0;i<n;i++)
    {
        v[i]*=v[i];
    }
    sort(v.begin(),v.end());
    for(int i=n-1;i>1;i--)
    {
        unordered_set<int> s;
        for(int j = i-1;j>-1;j--)
        {
            if(s.count(v[i] - v[j]))
                return true;
            
            s.insert(v[j]);
        }
    }
    return false;
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
    if(checkTrip(v,n))
    {
        cout<<"yes"<<endl;
    }
    else
        cout<<"no";
    return 0;
}