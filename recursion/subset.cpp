#include <bits/stdc++.h>
using namespace std;
vector<string> solve(string s)
{
    int n = s.length();
    // string sub = "";
    vector<string> ans;
    for (int num = 0; num < (1 << n); num++)
    {
        string sub = "";
        for (int i = 0; i < n; i++)
        {
            if (num & (1 << i))
            {
                sub += s[i];
            }
        }
        if (sub.length() >= 0)
        {
            ans.push_back(sub);
        }
    }

    // sort(ans.begin(), ans.end());
    return ans;
}
int main()
{
    string s;
    cin >> s;
    vector<string> ans = solve(s);
    for (auto it : ans)
    {
        cout << it << endl;
    }
    return 0;
}