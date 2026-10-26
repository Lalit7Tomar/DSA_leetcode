class Solution {
public:
    bool check(vector<int>& nums) {
        // find index of minimum ele
        // start from there
         int drop=0;
         for(int i=0;i<nums.size()-1;i++){
            if(nums[i]>nums[i+1]) drop++; 
         }
         if(drop>1 || (drop>0 && nums[nums.size()-1]>nums[0])) return false;
         return true;
            }
};