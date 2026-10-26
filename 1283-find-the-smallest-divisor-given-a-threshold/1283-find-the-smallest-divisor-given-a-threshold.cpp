
class Solution {
public:
    int smallestDivisor(vector<int>& nums, int threshold) {
         int ma=INT_MIN;
         for(int i=0;i<nums.size();i++){
            if(nums[i]>ma) ma=nums[i];
         }
          int s=1;
          int ans=ma;
          while(s<=ma){
            int mid=(s+ma)/2;
            int res=0;
            for(int i=0;i<nums.size();i++){
                if(nums[i]%mid==0) res=res+nums[i]/mid;
                else{
                    res=res+nums[i]/mid+1;
                }
            }
             if(res>threshold){
                s=mid+1;
             } 
             else if(res<=threshold){
                ans=min(ans,mid);
                ma=mid-1;
             }
          }
          return ans;
    }
};