#include<bits/stdc++.h>
using namespace std;
void solve(vector<int>& v,int size)
{
    for(int i=0;i<size;i++)
    {
        int j;
        for(int j=i-1;j>=0;j--)
        {
            if(v[j]>v[i])
            {
                cout<<v[j]<<" ";break;
            }
        }

    }
}
void solve1(vector<int>& v,int size)
{
    stack<int> st;
    st.push(v[0]);
    cout<<"-1 ";
    for(int i=1;i<size;i++)
    {
        while(st.empty()==false && st.top()<=v[i])
        {
            st.pop();
        }
        int prevGreatest = (st.empty())?-1:st.top();
        cout<<prevGreatest<<" ";
        st.push(v[i]);
    }

}
int main()
{
    int size;
    cin >>size;
    vector<int> v(size);
    for(int i=0;i<size;i++)
    {
        cin>>v[i];
    }
    solve1(v,size);
    return 0;
}