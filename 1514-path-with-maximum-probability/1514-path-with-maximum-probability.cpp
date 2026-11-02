class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start_node, int end_node) {
        vector<vector<pair<int,double>>> adja(n);
        for(int i=0;i<edges.size();i++){
            adja[edges[i][0]].push_back({edges[i][1],succProb[i]});
                        adja[edges[i][1]].push_back({edges[i][0],succProb[i]});

        }
        vector<double> nodes(n);
        priority_queue<pair<double,int>> pq;
        pq.push({1.0,start_node});
        nodes[start_node]=1.0;
        while(!pq.empty()){
            pair<double,int> ele=pq.top();
            pq.pop();
            if(nodes[ele.second]>ele.first) continue;
            for(int i=0;i<adja[ele.second].size();i++){
                if(adja[ele.second][i].second*ele.first>nodes[adja[ele.second][i].first]){
                   nodes[adja[ele.second][i].first]=adja[ele.second][i].second*ele.first;
                    pq.push({nodes[adja[ele.second][i].first],adja[ele.second][i].first});
                }
            }
        }
        return nodes[end_node];
    }
};