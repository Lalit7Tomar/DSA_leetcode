class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        // calculate minimum dist to all nodes
      
        vector<vector<vector<int>>> ans(n+1);
         for(int i=0;i<times.size();i++){
            ans[times[i][0]].push_back({times[i][1],times[i][2]});
         }
         vector<int> nodes(n+1,INT_MAX);
         nodes[k]=0;
         priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
         pq.push({0,k});
         while(!pq.empty()){
            pair<int,int> p=pq.top();
            pq.pop();
            if(p.first>nodes[p.second]) continue;
            for(int i=0;i<ans[p.second].size();i++){

                if(ans[p.second][i][1]+p.first<nodes[ans[p.second][i][0]]) {
                nodes[ans[p.second][i][0]]=ans[p.second][i][1]+p.first;
                  pq.push({ nodes[ans[p.second][i][0]],ans[p.second][i][0]});
                }
            }
         }
        int max_time = 0;
        for(int i = 1; i <= n; i++){
            if(nodes[i] == INT_MAX) return -1;
            max_time = max(max_time, nodes[i]);
        }
        
        return max_time;
    }
};