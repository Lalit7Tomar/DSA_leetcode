class Solution {
public:
  vector<int> twoSum(vector<int>& nums, int target) {
   unordered_map<int,int> m;
   for(int i=0;i<nums.size();i++){
      m[nums[i]]=i;
   }
   vector<int> ans;
   for(int i=0;i<nums.size();i++){
       int complement=target-nums[i];
       auto it=m.find(complement);
       if(it!=m.end() && it->second!=i){
          ans.push_back(i);
          ans.push_back(it->second);
          break;
       }
   }
   return ans;
}
};