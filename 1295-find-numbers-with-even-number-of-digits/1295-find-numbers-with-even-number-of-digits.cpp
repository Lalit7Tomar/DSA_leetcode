class Solution {
public:
    int findNumbers(vector<int>& nums) {
        int numbers=0;
        for(int i=0;i<nums.size();i++){
            int a=nums[i];
            int noofdigits=0;
            while(a!=0){
                a=a/10;
                noofdigits++;
            }
            if(noofdigits%2==0) numbers++;
        }
        return numbers;
    }
};