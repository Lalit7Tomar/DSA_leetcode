class Solution {
public:
      
    
     int uniqueways(int m,int n,vector<vector<int>>& dp){
        // either we have to ove upward or left
       
        if(m==0 && n==0) return 1;
        if(m<0 || n<0) return 0;
        if(dp[m][n]!=-1) return dp[m][n];
        int leftway=uniqueways(m,n-1,dp);
        int upway=uniqueways(m-1,n,dp);
        return dp[m][n]=leftway+upway;
     } 
    int uniquePaths(int m, int n) {
    // recursion 
      vector<vector<int>> dp(m,vector<int>(n,-1));
        return uniqueways(m-1,n-1,dp);     
    }
};