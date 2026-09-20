class Solution {
public:
    int uniqueways(int m,int n,vector<vector<int>>& dp,vector<vector<int>>& obstacleGrid){
        // either we have to ove upward or left
       
        if(m==0 && n==0) return 1;
        if(m<0 || n<0 || obstacleGrid[m][n]==1) return 0;
        if(dp[m][n]!=-1) return dp[m][n];
        int leftway=uniqueways(m,n-1,dp,obstacleGrid);
        int upway=uniqueways(m-1,n,dp,obstacleGrid);
        return dp[m][n]=leftway+upway;
     } 
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
         int m=obstacleGrid.size();
         int n=obstacleGrid[0].size();
         if( obstacleGrid[0][0]==1) return 0;
          if(m==1 && n==1 && obstacleGrid[m-1][n-1]==1) return 0;
         if(m==0 && n==0 || (m==1 && n==1)) return 1;
         vector<vector<int>> dp(m,vector<int>(n,-1));
        return uniqueways(m-1,n-1,dp,obstacleGrid);     
    }
};