class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
         sort(nums.begin(),nums.end());
         int i=0;
         int j=1;
         int k=nums.size()-1;
         if(nums.size()==3){
            int sum=nums[0]+nums[1]+nums[2];
            if(sum==0){
                return {{nums[0],nums[1],nums[2]}};
            }
            else{
                return {};
            }
         }
          vector<vector<int>> ans;
         for(int i=0;i<nums.size();i++){
            
           
            if(i>0 && nums[i]==nums[i-1] ){
               continue;
            }
            j=i+1;
            while(j<k){
            if(nums[i]+nums[j]+nums[k]>0){
                k--;
                
            }
            else if(nums[i]+nums[j]+nums[k]<0){
                j++;

            }
            else{
                ans.push_back({nums[i],nums[j],nums[k]});
                while(j<k && nums[j]==nums[j+1] ){
                    j++;
                }
                j++;
                while(j<k && nums[k]==nums[k-1] ){
                    k--;
                }
                k--;
            }
            
         }
         k=nums.size()-1;
         }
         return ans;
    }
};