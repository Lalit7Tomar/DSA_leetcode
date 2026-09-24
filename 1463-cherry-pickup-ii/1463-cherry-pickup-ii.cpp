class Solution {
public:
    
    int cherryPickup(vector<vector<int>>& grid) {
        vector<vector<vector<int>>> dp(grid.size(),vector<vector<int>>(grid[0].size(),vector<int>(grid[0].size(),-1)));
        for(int i=0;i<grid[0].size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(i==j) dp[grid.size()-1][i][j]=grid[grid.size()-1][i];
                else{
                    dp[grid.size()-1][i][j]=grid[grid.size()-1][i]+grid[grid.size()-1][j];
                }
            }
        }
        int n=grid.size();
        int m=grid[0].size();
        for (int i = n - 2; i >= 0; i--) {
            for (int j1 = 0; j1 < m; j1++) {
                for (int j2 = 0; j2 < m; j2++) {

                    int maxele = -1e9; 
                    for (int dj1 = -1; dj1 <= 1; dj1++) {
                        for (int dj2 = -1; dj2 <= 1; dj2++) {
                            
                            int nj1 = j1 + dj1; 
                            int nj2 = j2 + dj2;
                            if (nj1 >= 0 && nj1 < m && nj2 >= 0 && nj2 < m) {
                                maxele = max(maxele, dp[i + 1][nj1][nj2]);
                            }
                        }
                    }

                    int currentCherries = (j1 == j2) ? grid[i][j1] : (grid[i][j1] + grid[i][j2]);
                    
                    dp[i][j1][j2] = currentCherries + maxele;
                }
            }
        }

        return dp[0][0][m - 1];
    }
};