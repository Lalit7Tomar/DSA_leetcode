class Solution {
public:
    int dp[50][50][50];
    
    int recursion(vector<vector<int>>& grid, int i1, int j1, int i2, int n) {
        int j2 = i1 + j1 - i2;
        
        if (i1 >= n || j1 >= n || i2 >= n || j2 >= n || grid[i1][j1] == -1 || grid[i2][j2] == -1) {
            return -1e9;
        }
        
        if (i1 == n - 1 && j1 == n - 1) {
            return grid[i1][j1];
        }
        
        if (dp[i1][j1][i2] != -1) {
            return dp[i1][j1][i2];
        }
        
        int cherries = (i1 == i2 && j1 == j2) ? grid[i1][j1] : grid[i1][j1] + grid[i2][j2];
        
        int max_next = max({
            recursion(grid, i1 + 1, j1, i2 + 1, n),
            recursion(grid, i1, j1 + 1, i2 + 1, n),
            recursion(grid, i1 + 1, j1, i2, n),
            recursion(grid, i1, j1 + 1, i2, n)
        });
        
        return dp[i1][j1][i2] = cherries + max_next;
    }
    
    int cherryPickup(vector<vector<int>>& grid) {
        memset(dp, -1, sizeof(dp));
        int ans = recursion(grid, 0, 0, 0, grid.size());
        return max(0, ans);
    }
};