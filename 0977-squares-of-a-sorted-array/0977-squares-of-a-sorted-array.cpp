class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
       priority_queue<int,vector<int>,greater<int>> p;

       for(int i=0;i<nums.size();i++){
        nums[i]=nums[i]*nums[i];
         p.push(nums[i]);
       }
       vector<int> ans;
       while(!p.empty()){
          ans.push_back(p.top());
          p.pop();
       }
       return ans; 
    }
};