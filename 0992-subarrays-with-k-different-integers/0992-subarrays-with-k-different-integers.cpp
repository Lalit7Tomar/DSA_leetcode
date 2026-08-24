class Solution {
public:
    int atmostkele(vector<int>& nums, int k){
        unordered_map<int,int> m;
       int ans=0;
       int i=0;
       int j=0;
       while(j<nums.size()){
         m[nums[j]]++;
         while(m.size()>k){
           m[nums[i]]--;
           if(m[nums[i]]==0){
             m.erase(nums[i]);
         }
                      i++;

         }
         ans=ans+j-i+1;
         j++;
       }
       return ans;
    }
    int subarraysWithKDistinct(vector<int>& nums, int k) {
      return atmostkele(nums,k)-atmostkele(nums,k-1);
    
    
    
    }
    
    
    
    };