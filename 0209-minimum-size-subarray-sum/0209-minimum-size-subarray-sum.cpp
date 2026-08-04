class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        
     int i=0;
        int sum=0;
        int len=1;
        int j=0;
        int minlen=INT_MAX;
        while(j<nums.size()){
          sum+=nums[j];
          while(sum>=target){
             len=j-i+1;
             minlen=min(minlen,len);
             sum=sum-nums[i];
             i++;
          }
          j++;
        }
        if(minlen==INT_MAX) return 0;
        return minlen;
    }
};