
        class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        // min vallue of effort
        vector<vector<int>> ans(grid.size());
        for(int i=0;i<grid.size();i++){
            ans[i]=vector<int>(grid.size(),INT_MAX);
        }
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>> pq;
        // minheap declared
        ans[0][0]=0;
        pq.push({grid[0][0],{0,0}});
        vector<int> lt={-1,1,0,0};
        vector<int> rt={0,0,-1,1};
        while(!pq.empty()){
         pair<int,pair<int,int>> p=pq.top();
         pq.pop();
         if(p.second.second==grid.size()-1 && p.second.first==grid.size()-1){
             break;
         }
         //push all adjacent items
         for(int i=0;i<4;i++){
            if(p.second.first+lt[i]>=0 && p.second.first+lt[i]<grid.size() && p.second.second+rt[i]>=0 && p.second.second+rt[i]<grid.size()){
              if(grid[p.second.first+lt[i]][p.second.second+rt[i]]<ans[p.second.first+lt[i]][p.second.second+rt[i]] && p.first<grid[p.second.first+lt[i]][p.second.second+rt[i]]){
                ans[p.second.first+lt[i]][p.second.second+rt[i]]=grid[p.second.first+lt[i]][p.second.second+rt[i]];
                pq.push({grid[p.second.first+lt[i]][p.second.second+rt[i]],{p.second.first+lt[i],p.second.second+rt[i]}});
              }
              else if(p.first<ans[p.second.first+lt[i]][p.second.second+rt[i]] && p.first>=grid[p.second.first+lt[i]][p.second.second+rt[i]]){
                ans[p.second.first+lt[i]][p.second.second+rt[i]]=p.first;
                pq.push({p.first,{p.second.first+lt[i],p.second.second+rt[i]}});
              }
            }
           
         }
        }
        return ans[grid.size()-1][grid.size()-1];
    }
};
   