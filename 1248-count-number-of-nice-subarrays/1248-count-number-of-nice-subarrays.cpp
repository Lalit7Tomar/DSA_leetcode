class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int left=0;
        int right=0;
        int ans=0;
        int oddcount=0;
       /*
         1-see calculate subarraywith k zeros.
         2-now move the left pointer until odd number is found.
         3.move right until odd number is found
         multiply
         update left pointer
       */  
         while(right<nums.size()){
            while(right<nums.size() && oddcount<k){
                if(nums[right]%2==1){
                    oddcount++;
                }
                 right++;

            }
            if(oddcount==k){
                int c=left;
                int d=right;
                while(c<d && nums[c]%2==0){
                    c++;
                }
                while(d<nums.size() && nums[d]%2==0){
                    d++;
                }
                ans=ans+(c-left+1)*(d-right+1);
                left=c+1;
                right=d;
                oddcount--;
            }
         }
         return ans;
    }
};