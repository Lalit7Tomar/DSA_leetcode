class Solution {
public:
    int splitArray(vector<int>& nums, int k) {
       int s=INT_MIN;
        int e=0;
        int ans=0;
        for(int i=0;i<nums.size();i++){
            if(s<nums[i]){
                s=nums[i];
            }
            e=e+nums[i];
        }
        while(s<=e){
            int mid=(s+e)/2;
            int count=1;
            int sum=0;
            for(int i=0;i<nums.size();i++){
                if(sum+nums[i]>mid){
                    count++;
                    sum=nums[i];
                    if(count>k){
                        s=mid+1;
                        break;
                    }
                }
                else{
                    sum=sum+nums[i];
                }
            }
            if(count<=k){
                e=mid-1;
                ans=mid;
            }
        }
          return ans; 
    }
};