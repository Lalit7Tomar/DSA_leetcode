class Solution {
public:
    int f(vector<int>& nums,int index,vector<int>& d){
         if(index==0) return nums[0];
         if(index<0) return 0;
         if(d[index]!=-1) return d[index];
         int take=nums[index]+f(nums,index-2,d);
         int not_take=f(nums,index-1,d);

         return d[index]=max(take,not_take);
    }
    int rob(vector<int>& nums) {
        /*
          no two adjacent should be stolen
           f(n)=arr[n]+f(n-2);
           or
           f(n)=f(n-1);
            t.c=o(2^n);
        */
        vector<int> d(nums.size(),-1);
        return f(nums,nums.size()-1,d);
        
    }
};