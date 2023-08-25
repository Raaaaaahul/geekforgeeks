#include<bits/stdc++.h>
using namespace std;
int solve(int n,int last,vector<vector<int>>& dp,vector<vector<int>>& points)
{
    if(n==0)
    {
        int maxi = 0;
        for(int i=0;i<=2;i++)
        {
            if(i!=last)
            {
                maxi = max(points[0][i],maxi);
            }
        }
        return maxi;
    }
    if(dp[n][last]!=-1)
    {
        return dp[n][last];
    }
    int maxi = 0;
    for(int i=0;i<=2;i++)
    {
        if(i!=last)
        {
            int activity = points[n][i] + solve(n-1,i,dp,points);
            maxi = max(activity,maxi);
        }
    }
    return dp[n][last]=maxi;
}
int ninjaTraining(int n,vector<vector<int>>& points)
{
    vector<vector<int>> dp(n,vector<int>(4,-1));
    return solve(n-1,3,dp,points);
}
int main()
{
    
  vector < vector < int > > points = {{10,40,70},
                                      {20,50,80},
                                      {30,60,90}};

  int n = points.size();
  cout << ninjaTraining(n, points);
}