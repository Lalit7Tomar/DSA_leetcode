class Solution {
public:
    void nextPermutation(vector<int>& nums) {
         int flag=0;
        for(int i=nums.size()-1;i>0;i--){

            if(nums[i]>nums[i-1]){
                flag=1;
                int j=i;
                int minspec=nums[i];
                while(j<nums.size() &&  nums[j]>nums[i-1] ){
                    j++;
                }
                j=j-1;
                swap(nums[i-1],nums[j]);
                //now reverse the remaining array
                int k=i;
                int g=nums.size()-1;
                while(k<g){
                    swap(nums[k],nums[g]);
                    k++;
                    g--;
                }
                return;
            }
            else{
                continue;
            }
           
        }
        if(flag==0){
            //swap
            int i=0;
            int j=nums.size()-1;
            while(i<j){
                swap(nums[i],nums[j]);
                i++;
                j--;
            }
        }
        return;
    }
};