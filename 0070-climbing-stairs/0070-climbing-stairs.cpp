class Solution {
public:
    vector<int> dp;
    int climbStairs(int n) {
        if(dp.empty()) dp.resize(n+1,-1);
       if(n==0 || n==1) return 1;
       if(dp[n]!=-1) return dp[n];
       int left=climbStairs(n-1);
       int right=climbStairs(n-2);
       dp[n]=left+right;
       return left+right;   
    }
};