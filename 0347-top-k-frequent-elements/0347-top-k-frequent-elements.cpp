class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> m;
        for(int i=0;i<nums.size();i++){
            m[nums[i]]++;
        }
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        for(int i=0;i<k;i++){
            pq.push({m[nums[i]],nums[i]});
           m.erase(nums[i]);
        }
        for(auto it=m.begin();it!=m.end();++it){
          if(it->second>pq.top().first){
            pq.pop();
            pq.push({it->second,it->first});
          }
          
        }
        vector<int> ans;
        for(int i=0;i<k;i++){
            ans.push_back(pq.top().second);
            pq.pop();
        }
        return ans;
    }
};