class Solution {
public:
    int findMin(vector<int>& nums) {
                int s=0;
        int e=nums.size()-1;
        while(s<=e){
            int mid=s+(e-s)/2;
            if(s==e){
                return nums[s];
            }
            if(nums[s]<nums[mid]){
                if(nums[e]<nums[s]){
                    s=mid+1;
                }
                else if(nums[e]>=nums[mid]){
                    return nums[s];
                }
            }
            else if(nums[mid]<nums[s]){
                e=mid;  
                          }
            else if(nums[mid]==nums[s] && e==s+1){
                return min(nums[e],nums[s]);
            }
        }
        return nums[s];
    }
};