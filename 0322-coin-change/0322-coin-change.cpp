class Solution {
public:
   int coinChange(vector<int>& coins, int amount) {
              vector<vector<int>> dp(coins.size(),vector<int>(amount+1,-1));
       for(int i=0;i<=amount;i++){
         if(i%coins[0]==0){
            dp[0][i]=i/coins[0];
         }
         else{
            dp[0][i]=INT_MAX;  
         }
       }
       for(int i=0;i<coins.size();i++){
        dp[i][0]=0;
       }
        for(int i=1;i<coins.size();i++){
            for(int j=1;j<=amount;j++){
                int take=1e9;
                if(coins[i]<=j){
                    take=1+dp[i][j-coins[i]];
                }
                int not_take=dp[i-1][j];
              dp[i][j]=min(take,not_take);
               
        }
    }
      if(dp[coins.size()-1][amount]>=1e9) return -1;
           return dp[coins.size()-1][amount];
   }
};
