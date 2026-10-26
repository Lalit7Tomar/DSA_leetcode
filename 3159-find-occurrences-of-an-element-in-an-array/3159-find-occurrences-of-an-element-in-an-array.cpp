class Solution {
public:
    vector<int> occurrencesOfElement(vector<int>& nums, vector<int>& queries, int x) {
        vector<int> m;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==x){
                m.push_back(i);
            }
        }
        vector<int> result;
        for(int i=0;i<queries.size();i++){
            int t=queries[i];
            if(m.size()<t) result.push_back(-1);
            else if(m.size()>=t) result.push_back(m[t-1]);
        }
        return result;
    }
};