class Solution {
public:
/*
10-skip,
1->2 or 7 or 6 or 1 or 5
2->6or 1 or 5
7

*/
    set<vector<int>> ans;
    void recursivecallback(int index,vector<int>& candidates,int target,vector<int>& temp){
      if(target==0){
        sort(temp.begin(),temp.end());
        ans.insert(temp);
        return;
      }
        else if(index<candidates.size() && candidates[index]>target){
            return;
        }
        for(int i=index;i<candidates.size();i++){
            if(i!=index && candidates[i]==candidates[i-1]) continue;
            if(candidates[i]<=target){
                temp.push_back(candidates[i]);
                recursivecallback(i+1,candidates,target-candidates[i],temp);
                temp.pop_back();
            }
        }   


    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
          vector<int> temp;
          sort(candidates.begin(),candidates.begin() + candidates.size());
          
           recursivecallback(0,candidates,target,temp);
           vector<vector<int>> h;
           for(auto it=ans.begin();it!=ans.end();++it){
              h.push_back(*it);
           }
          return h;
    }
};