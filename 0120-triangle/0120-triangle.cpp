class Solution {
public:
    int recursion(vector<vector<int>>& triangle, int i, int j, vector<vector<int>>& dp) {
        if (i == triangle.size() - 1) return triangle[i][j];
                if (dp[i][j] != -1) return dp[i][j];
        
        int down = triangle[i][j] + recursion(triangle, i + 1, j, dp);
        int corner = triangle[i][j] + recursion(triangle, i + 1, j + 1, dp);
        
        return dp[i][j] = min(down, corner);
    }
    
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        
        vector<vector<int>> dp(n);
       for(int i=triangle.size()-2;i>=0;i--){
            for(int j=0;j<triangle[i].size();j++){
                triangle[i][j]=triangle[i][j]+min(triangle[i+1][j],triangle[i+1][j+1]);
            }
        }
        return triangle[0][0];
    }
};