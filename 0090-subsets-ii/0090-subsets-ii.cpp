class Solution {
public:
    set<vector<int>> s;
    // o(n^2) 
    void recursion(vector<int>& nums,vector<int>& curr,int index){
      if(index==nums.size()){
        s.insert(curr);
        return;
      }
   
    recursion(nums,curr,index+1);
     curr.push_back(nums[index]);
     
      recursion(nums,curr,index+1);
      curr.pop_back();
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        // i have 2 choices-whethe to take that element or not.
        vector<int> curr;
        sort(nums.begin(),nums.end());
        recursion(nums,curr,0);
       
         
         vector<vector<int>> subset(s.begin(),s.end());
        

           return subset;


           }
};