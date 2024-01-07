#include<bits/stdc++.h>
using namespace std;

string solve(string& A)
{
    int freq[26] = {0};
		    queue<char> q;
		    string ans = "";
		    for(int i=0;i<A.length();i++)
		    {
		        freq[A[i]-'a']++;
		        if(freq[A[i]-'a']==1)
		        {
		            q.push(A[i]);
		        }
		        while(q.empty()==false and freq[q.front() - 'a']>1)
		        {
		            q.pop();
		        }
		        if(q.empty())
		        {
		            ans+='#';
		        }
		        else
		        {
		            ans += q.front();
		        }
		    }
		    return ans;
}

int main()
{
    string s = "aabc";
    cout<<solve(s);
    return 0;
}