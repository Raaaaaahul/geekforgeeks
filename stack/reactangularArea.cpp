#include<bits/stdc++.h>
using namespace std;
int solve(vector<int>& v,int n)
{
    int res = 0;
    for(int i=0;i<n;i++)
    {
        int curr = v[i];
        for(int j = i-1;j>=0;j--)
        {
            if(v[j]>=v[i])
            {
                curr+=v[i];
            }
            else
            {
                break;
            }
        }
        for(int j=i+1;j<n;j++)
        {
            if(v[j]>=v[i])
            {
                curr+=v[i];
            }
            else
                break;
        }
        res = max(res,curr);
    }
    return res;
}
int solvEff(vector<int>& v,int n)
{
    stack<int> st;
    int res = 0;
    for(int i=0;i<n;i++)
    {
        while(st.empty()==false and v[st.top()]>=v[i])
        {
            
            int tp = st.pop();
            int curr = v[tp]*(st.empty()?i:i-st.top()-1);
            res = max(curr,res);
        }
        st.push(i);
        while(st.empty())
        {s
            int tp = st.pop():
            int c = v[tp]*(st.empty()?n:(n-st.top()-1));
            res = max(res,c)
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
    cout<<solvEff(v,size);
    return 0;
}