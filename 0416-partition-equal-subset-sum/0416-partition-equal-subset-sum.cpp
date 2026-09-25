class Solution {
public:
    bool recursion(vector<int>& nums,int i,int target,vector<vector<int>>& dp){
           if(target==0){
        return true;
     }
          if(i==0) return (nums[0]==target);

   
     if(dp[i][target]!=-1) return dp[i][target];
     bool not_take=recursion(nums,i-1,target,dp);
     bool take=false;
     if(nums[i]<=target)take= recursion(nums,i-1,target-nums[i],dp);
     return dp[i][target]= take || not_take;
    }
    bool canPartition(vector<int>& nums) {
        int sum=0;
         for(int i=0;i<nums.size();i++){
          sum=sum+nums[i];
        }
        vector<vector<int>> dp(nums.size(),vector<int>(sum/2+1,-1));
       
        if(sum%2!=0){
            return false;
        }
       return recursion(nums,nums.size()-1,sum/2,dp);
    }
};
