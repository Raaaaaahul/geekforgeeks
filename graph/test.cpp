#include <iostream>
#include <string>
#include <vector>
#include <queue>
using namespace std;

vector<int> getNext(string &needle) {
    int m = needle.length();
    vector<int> next(m);
    for (int i = 1, len = 0; i < m;) {
        if (needle[i] == needle[len]) {
            next[i++] = ++len;
        } else if (len == 0) {
            ++i;
        } else {
            len = next[len - 1];
        }
    }
    return next;
}

string dfs(vector<vector<pair<int, char>>> &dp, int len, int x) {
    return len ? (dfs(dp, len - 1, dp[len][x].first) + dp[len][x].second) : " ";
}

string solve(string &s1, const string &s2) {
    int n = s1.length(), m = s2.length(), len = n + m - 1;
    string r(len, '?');
    for (int i = 0; i < m; ++i) {
        if (s2[i] == 'T') {
            for (int j = 0; j < n; ++j) {
                if (r[i + j] != '?' && r[i + j] != s1[j]) {
                    return "-1";
                }
                r[i + j] = s1[j];
            }
        }
    }
    vector<int> next = getNext(s1);
    vector<vector<pair<int, char>>> dp(len + 1, vector<pair<int, char>>(len + 1, {-1, '-'}));
    queue<int> q;
    q.push(0);
    for (int i = 0; i < len; ++i) {
        char from = r[i], to = r[i];
        if (r[i] == '?') {
            from = 'A';
            to = 'B';
        }
        for (int j = q.size(); j; --j) {
            int x = q.front();
            q.pop();
            for (char c = from; c <= to; ++c) {
                int y = x == n ? next[x - 1] : x;
                for (; y && c != s1[y]; y = next[y - 1])
                    ;
                int temp = c == s1[y] ? (y + 1) : 0;
                if ((i >= n - 1 && s2[i - n + 1] == 'F' && temp == n) || (dp[i + 1][temp].first >= 0)) {
                    continue;
                }
                dp[i + 1][temp] = {x, c};
                if (i + 1 == len) {
                    return dfs(dp, len, temp);
                }
                q.push(temp);
            }
        }
    }
    return "-1";
}


int main() {

ios::sync_with_stdio(0);

cin.tie(0);

int T;

cin >> T;

for (int t_i = 0; t_i < T; t_i++) 

{

string S1;

cin >> S1;

string S2;

cin >> S2;

string out_;

out_ = solve (S1, S2);

cout << out_;
cout <<"\n";}}