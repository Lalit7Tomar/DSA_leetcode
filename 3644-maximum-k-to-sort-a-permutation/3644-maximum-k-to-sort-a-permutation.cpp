class Solution {
public:
    int sortPermutation(vector<int>& nums) {
        /// array ko sort isi method se karna
        int a=-1;
        for(int i=0;i<nums.size();i++){
            if(nums[i]!=i) a=a&nums[i];
        }
        if(a==-1) a=0;
        return a;
    }
};