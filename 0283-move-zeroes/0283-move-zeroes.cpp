class Solution {
public:
    void moveZeroes(vector<int>& nums) {
       int i=0;
        int j=0;
        int n=nums.size();
        while(i!=n-1){
          while(i<nums.size() && nums[i]!=0){
            i++;
          }
          
          j=i;
          while(j<nums.size() && nums[j]==0){
            j++;
          }
          if(j==n) break;
          int temp=nums[j];
          nums[j]=nums[i];
          nums[i]=temp;
          
          
        }
        return;  
    }
};