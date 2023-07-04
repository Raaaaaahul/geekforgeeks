#include<bits/stdc++.h>
using namespace std;
void solve(vector<int>& v,int n)
{
    vector<int> res(n,1);
    for(int i=0;i<n;i++)
    {
        for(int j=i-1;j>=0 and v[j]<=v[i];j--)
        {
            res[i]++;
        }
    }
    for(int i=0;i<n;i++)
    {
        cout<<res[i]<<" ";
    }
}
void solve1(vector<int>& v,int n)
{
    stack<int> st;
    st.push(0);
    cout<<"1 ";
    for(int i=1;i<n;i++)
    {
        while(st.empty()==false and v[st.top()]<=v[i])
        {
            st.pop();
        }
        int span = st.empty()?i+1:i-st.top(); 
        cout<<span<<" ";
        st.push(i);
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
    cout<<endl;
    solve1(v,size);
    return 0;
}