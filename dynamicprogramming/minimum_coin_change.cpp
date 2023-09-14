 long long int solve(int coins[],int n,int sum,vector<vector<long long int>>&dp){
      if(sum==0){
            return 1;
        }
        if(n==0){
            return 0;
        }
    // for(int i=0;i<n+1;i++){
    //     for(int j=0;j<sum+1;j++){
    //         if(i==0){
    //             dp[i][j]=0;
    //         }
    //         if(j==0){
    //             dp[i][j]=1;
    //         }
    //     }
    // }
    // for(int i=1;i<n+1;i++){
    //     for(int j=1;j<sum+1;j++){
    //          if(coins[i-1]<=j){
    //             dp[i][j]= dp[i][j-coins[i-1]]+dp[i-1][j];
    //         }else{
    //             dp[i][j]=dp[i-1][j];
    //         }
    //     }
    // }
    // return dp[n][sum];
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