class Solution {
public:
    bool dfs(vector<int>& nums,int index,vector<int>& visited){
      if(visited[index] || index>=nums.size()) return false;
      if(index==nums.size()-1) return true;
      
      visited[index]=1;
      for(int i=1;i<=nums[index];i++){
        
        if(dfs(nums,index+i,visited)) return true;
      }
      return false;

    }
    bool canJump(vector<int>& nums) {
        // dfs lagayenge
        vector<int> visited(nums.size(),0);
        if(nums.size()==0 || nums.size()==1) return true;
          return dfs(nums,0,visited); 
    }
};