class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
       int count=0;
       vector<vector<int>> ans;
        for(int i=0;i<intervals.size();i++){
            ans.push_back({intervals[i][1],intervals[i][0],i});
        }
        sort(ans.begin(),ans.begin()+ans.size());
        int i=0;
        int j=1;
        while(j<intervals.size()){
            
            if(j<intervals.size() && ans[i][0]>ans[j][1]){
                j++;
                count++;
            }
            else{
                i=j;
                j++;
            }
            
        }
        return count;
    }
};