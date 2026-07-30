class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> output;
        if(intervals.size()==0 || intervals.size()==1){
            return intervals;
        }
        sort(intervals.begin(),intervals.end());
        output.push_back(intervals[0]);
        int h=0;
        for(int i=1;i<intervals.size();i++){
            if(output[h][1]>=intervals[i][0] && output[h][1]<=intervals[i][1]){
                output[h][1]=intervals[i][1];
            }
           else if(output[h][1]>=intervals[i][0] && output[h][1]>intervals[i][1]){
                  continue;
            }
            else {
              vector<int> a={intervals[i][0],intervals[i][1]};
              output.push_back(a);
              h++;
            }

        }
        return output; 
    }
};