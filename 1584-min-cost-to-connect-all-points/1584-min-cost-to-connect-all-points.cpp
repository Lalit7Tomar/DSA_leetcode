class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        map<pair<int,int>,vector<pair<int,pair<int,int>>>> m;
        for(int i=0;i<points.size();i++){
            for(int j=i+1;j<points.size();j++){
                int dist=abs(points[i][0]-points[j][0])+abs(points[j][1]-points[i][1]);
                m[{points[i][0],points[i][1]}].push_back({dist,{points[j][0],points[j][1]}});
                m[{points[j][0],points[j][1]}].push_back({dist,{points[i][0],points[i][1]}});
                
            }
        }
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>> pq;
        pq.push({0,{points[0][0],points[0][1]}});
        int sum=0;
        set<pair<int,int>> s;
        while(s.size()<points.size()){
            pair<int,pair<int,int>> p=pq.top();
            pq.pop();
            if(s.find({p.second.first,p.second.second})==s.end()){
            s.insert({p.second.first,p.second.second});
           sum=sum+p.first;
            }
            for(auto it:m[{p.second.first,p.second.second}]){
                if(s.find({it.second.first,it.second.second})==s.end()){
                    pq.push({it.first,{it.second.first,it.second.second}});
                    
                }
            }
        }
        return sum;
    }
};