class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int total = accumulate(nums.begin(), nums.end(), 0);
        if (total % 2 != 0) return false;
        int target = total / 2;

        int n = nums.size();
        vector<vector<bool>> dp(n, vector<bool>(target + 1, false));

        for (int i = 0; i < n; i++) dp[i][0] = true;

        if (nums[0] <= target) dp[0][nums[0]] = true;

        for (int i = 1; i < n; i++) {
            for (int sum = 1; sum <= target; sum++) {
                bool notTake = dp[i-1][sum];
                bool take = false;
                if (nums[i] <= sum) take = dp[i-1][sum - nums[i]];
                dp[i][sum] = notTake || take;
            }
        }
        return dp[n-1][target];
    }
};
