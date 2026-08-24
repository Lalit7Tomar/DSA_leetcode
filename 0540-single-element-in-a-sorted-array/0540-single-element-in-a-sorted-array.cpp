class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int s=0;
        int e=nums.size()-1;
        int ans=0;
        if(nums.size()==1){
            return nums[0];
        }
        while(s<=e){
            int mid=(s+e)/2;
            if(s==e){
                return nums[s];
            }
            if(nums[mid]!=nums[mid+1] && nums[mid]!=nums[mid-1]){
                return nums[mid];
            }
            if((mid-s+1)%2==0){
                if(nums[mid]==nums[mid+1]){
                   e=mid-1;
                }
                else{
                    s=mid+1;
                }
            }
            else if((mid-s+1)%2!=0){
                if(nums[mid]==nums[mid+1]){
                    s=mid;
                }
                else{
                    e=mid;
                }

            }

        }
        return nums[s];
    }
};