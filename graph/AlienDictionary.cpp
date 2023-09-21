#include <bits/stdc++.h>
using namespace std;
class Solution{
    public:

    vector<int> topoSort(vector<vector<int>>& g,int k)
    {
        vector<int> indeg(k,0);
        for(int i=0;i<k;i++)
        {
            for(auto it:g[i])
            {
                indeg[it]++;
            }
        }

        queue<int> q;
        for(int i=0;i<k;i++)
        {
            if(indeg[i]==0)
            {
                q.push(i);
            }
        }

        vector<int> topo;
        while(q.empty()==false)
        {
            int node = q.front();
            q.pop();
            topo.push_back(node);
            for(auto it:g[node])
            {
                indeg[it]--;
                if(indeg[it]==0)
                {
                    q.push(it);
                }
            }
        }
        return topo;
    }
    string findOrder(string dict[], int N, int K) {
       //graph creation
       vector<vector<int>> g(K);
       for(int i=0;i<N-1;i++)
       {
            string s1 = dict[i];
            string s2 = dict[i+1];

            int len = min(s1.length(),s2.length());
            for(int ptr=0;ptr<len;ptr++)
            {
                if(s1[ptr]!=s2[ptr])
                {
                    g[s1[ptr]-'a'].push_back(s2[ptr]-'a');break;
                }
            }
       }
       vector<int> temp = topoSort(g,K);
       string res = "";
       for(auto it:temp)
       {
            res = res + char(it+'a');
       }
       return res;
    }
};

string order;
bool f(string a, string b) {
    int p1 = 0;
    int p2 = 0;
    for (int i = 0; i < min(a.size(), b.size()) and p1 == p2; i++) {
        p1 = order.find(a[i]);
        p2 = order.find(b[i]);
        //	cout<<p1<<" "<<p2<<endl;
    }

    if (p1 == p2 and a.size() != b.size()) return a.size() < b.size();

    return p1 < p2;
}
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, K;
        cin >> N >> K;
        string dict[N];
        for (int i = 0; i < N; i++) cin >> dict[i];
        
        Solution obj;
        string ans = obj.findOrder(dict, N, K);
        order = "";
        for (int i = 0; i < ans.size(); i++) order += ans[i];

        string temp[N];
        std::copy(dict, dict + N, temp);
        sort(temp, temp + N, f);

        bool f = true;
        for (int i = 0; i < N; i++)
            if (dict[i] != temp[i]) f = false;

        if(f)cout << 1;
        else cout << 0;
        cout << endl;
    }
    return 0;
}