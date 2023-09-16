 long long int solve(int coins[],int n,int sum,vector<vector<long long int>>&dp){
      if(sum==0){
            return 1;
        }
        if(n==0){
            return 0;
        }
        if(dp[n][sum]!=-1){
            return dp[n][sum];
        }
        if(coins[n-1]<=sum){
            return dp[n][sum]= solve(coins,n,sum-coins[n-1],dp)+solve(coins,n-1,sum,dp);
        }else{
            return dp[n][sum]=solve(coins,n-1,sum,dp);
        }
  }
  
    long long int count(int coins[], int n, int sum) {
        vector<vector<long long int>>dp(n+1,vector<long long int>(sum+1,-1));
        return solve(coins,n,sum,dp);
        
    }