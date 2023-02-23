class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        vector<pair<int,int> proj;
        int n = profits.size();
        for(int i=0;i<n;i++)
        {
            proj.push_back({capital[i],profits[i]});
        }
        sort(proj.begin(),proj.end());
        priority_queue<int> q;
        int ptr = 0;
        for(int i=0;i<k;i++)
        {
            while(ptr<n && proj[ptr].first<=w)
            {
                q.push(proj[ptr++].second);
            }
            if(q.empty())
            {
                break;
            }
            w+=q.top();
            q.pop();
        }
        return w;
    }
};