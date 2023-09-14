#include<bits/stdc++.h>
using namespace std;
 
bool cmp(const string lhs, const string rhs) {
   return lhs.length() < rhs.length();
}
 
bool check(string temp1,string temp2)
{
    set<int> s1;
    set<int> s2;

    for(int i=0;i<temp1.length();i++)
    {
        s1.insert(temp1[i]);
    }
    for(int i=0;i<temp2.size();i++)
    {
        s2.insert(temp2[i]);
    }
    for(auto it : s1)
    {
        if(s2.find(it)!=s2.end())
        {
            return false;
        }
    }
    return true;
}
int solve(vector<string>& vec,int n)
{
    int res = INT_MIN;
    for(int i=0;i<n-1;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            if(check(vec[i],vec[j])==false)
            {
                continue;
            }
            else
            {
                int prod = vec[i].length()*vec[j].length();
                res = max(res,prod);
            }
        }
    }
    return res;
}

int main() {
    string inputLine;
    getline(cin, inputLine); 
    vector<string> v;
    istringstream iss(inputLine); 
    string word;
    while (iss >> word) {
        v.push_back(word);
    }
    int n = v.size();
   
   sort(v.begin(), v.end(), cmp);
   reverse(v.begin(),v.end());
   int res = solve(v,v.size());
   if(res==INT_MIN)
   {
       cout<<-1;
   }
   else
   cout<<res;
   return 0;
}