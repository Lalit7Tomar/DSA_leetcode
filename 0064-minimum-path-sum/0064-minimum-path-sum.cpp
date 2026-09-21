class Solution {
public:
     int ans=INT_MAX;

    int recursion(vector<vector<int>>& grid,int rowindex,int columnindex,vector<vector<int>>& dp){
       if(rowindex==0 && columnindex==0) return grid[0][0];
       if(rowindex<0 || columnindex<0) return INT_MAX/2;
       if(dp[rowindex][columnindex]!=-1) return dp[rowindex][columnindex];
        return dp[rowindex][columnindex]=min(grid[rowindex][columnindex]+recursion(grid,rowindex-1,columnindex,dp),
        grid[rowindex][columnindex]+recursion(grid,rowindex,columnindex-1,dp));
    }
    int minPathSum(vector<vector<int>>& grid) {
     vector<vector<int>> dp(grid.size(), vector<int>(grid[0].size(), -1));       // we will explore all possible paths by recursion and then clculate the minimum path
       return recursion(grid,grid.size()-1,grid[0].size()-1,dp);
    }
};