class Solution {
public:
     vector<vector<int>> ans;
     
    void recursion(int index,int remainingsum,vector<int>& cand,vector<int>& temp){
      
      if(remainingsum==0){
        ans.push_back(temp);
        return;
      }
     
        for(int j=index;j<cand.size();j++){
            if(remainingsum-cand[j]>=0){
               temp.push_back(cand[j]);
             recursion(j,remainingsum-cand[j],cand,temp);
            temp.pop_back();        
            }}
     
    ;

     return;
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> temp;
        recursion(0,target,candidates,temp);
        

        return ans;
    }
};