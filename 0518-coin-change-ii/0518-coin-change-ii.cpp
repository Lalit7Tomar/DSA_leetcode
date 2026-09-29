class Solution {
public:
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        // dp[i][j] = number of ways to make amount 'j' using first 'i' coins
        vector<vector<uint64_t>> dp(n, vector<uint64_t>(amount + 1, 0));
        
        // Base case: 1 way to make amount 0 (pick 0 coins)
        for (int i = 0; i < n; i++) {
            dp[i][0] = 1;
        }
        
        for (int i = 0; i < n; i++) {
            for (int j = 1; j <= amount; j++) {
                
                // notselect: value from the row above (index - 1)
                uint64_t notselect = (i > 0) ? dp[i - 1][j] : 0;
                
                // select: value from the SAME row, but smaller amount
                uint64_t select = (j >= coins[i]) ? dp[i][j - coins[i]] : 0;
                
                // Total ways is the sum of both choices
                dp[i][j] = select + notselect;
            }
        }
        
        return dp[n - 1][amount];
    }
};