class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int count=0;
        vector<int> ans;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==1){
                ans.push_back(i);
            }
        }
       if (goal == 0) {
            int count = 0, zero_streak = 0;
            for (int num : nums) {
                if (num == 0) {
                    zero_streak++;
                    count += zero_streak;
                } else {
                    zero_streak = 0;
                }
            }
            return count;
        }
        int k=goal;
        int i=0;
        int j=i+k-1;
        while(j<ans.size()){
           int leftzero=0;
           if(i==0){
            leftzero=ans[i];
           }
           else{
            leftzero=ans[i]-ans[i-1]-1;
           }
           int rightzero=0;
           if(j==ans.size()-1){
              rightzero=nums.size()-1-ans[j];
           }
           else{
            rightzero=ans[j+1]-ans[j]-1;
           }
           count=count+(leftzero+1)*(rightzero+1);
           i++;
           j++;
        }
        return count;
    }
};