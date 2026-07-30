class Solution {
public:
    int maxSubArray(vector<int>& nums) {
         int sum=0;
        int maxe=INT_MIN;
        for(int i=0;i<nums.size();i++){
            sum=sum+nums[i];
            if(sum>maxe){
               maxe=sum;
               if(sum<0){
                  sum=0;
               }
               
            }
            else{
               
                if(sum<0){
                    sum=0;
                }
            }
        }
        return maxe;
    }
    
};