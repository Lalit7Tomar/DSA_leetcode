class Solution {
public:
   int findTargetSumWays(vector<int>& nums, int target) {
    int sum=0;
    for(int i=0;i<nums.size();i++){
        sum=sum+nums[i];
    }
    vector<vector<int>> dp(nums.size(),vector<int>(2*sum+1,0));
     dp[0][sum]=0;
    
      dp[0][sum + nums[0]] += 1;
        dp[0][sum - nums[0]] += 1;
     for(int i=0;i<nums.size()-1;i++){
       for(int j=0;j<dp[0].size();j++){
        if(dp[i][j]!=0){
            dp[i+1][j+nums[i+1]]+=dp[i][j];
            dp[i+1][j-nums[i+1]]+=dp[i][j];
        }
       }
     }
     if(target>sum) return 0;
     if(target<-1*sum) return 0;
      return dp[nums.size()-1][sum+target];
        
    }
};