class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<pair<int, int>>> adj(n);
        for(int i = 0; i < edges.size(); i++) {
            adj[edges[i][0]].push_back({edges[i][1], edges[i][2]});
            adj[edges[i][1]].push_back({edges[i][0], edges[i][2]});
        }
        
        int minCities = INT_MAX;
        int bestCity = -1;
        
        for(int i = 0; i < n; i++) {
            priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
            
            vector<int> dist(n, INT_MAX);
            
            pq.push({0, i});
            dist[i] = 0;
            
            while(!pq.empty()) {
                auto [currentDist, u] = pq.top();
                pq.pop();
                
                if(currentDist > dist[u]) continue;
                
                for(auto& neighbor : adj[u]) {
                    int v = neighbor.first;
                    int weight = neighbor.second;
                    
                    if(dist[u] + weight < dist[v]) {
                        dist[v] = dist[u] + weight;
                        pq.push({dist[v], v});
                    }
                }
            }
            
            int reachableCount = 0;
            for(int j = 0; j < n; j++) {
                if(i != j && dist[j] <= distanceThreshold) {
                    reachableCount++;
                }
            }
            
            if(reachableCount < minCities || (reachableCount == minCities && i > bestCity)) {
                minCities = reachableCount;
                bestCity = i;
            }
        }
        
        return bestCity;
    }
};