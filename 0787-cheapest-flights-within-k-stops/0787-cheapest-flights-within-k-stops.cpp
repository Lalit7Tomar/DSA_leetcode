class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        // dist[i] stores the minimum cost to reach node i within the current stop limit
        vector<int> dist(n, INT_MAX);
        dist[src] = 0;

        // Perform k + 1 relaxations (at most k stops means k + 1 flights)
        for (int i = 0; i <= k; ++i) {
            vector<int> temp = dist; // Use temp to avoid using updated values from the same iteration
            for (const auto& flight : flights) {
                int u = flight[0];
                int v = flight[1];
                int price = flight[2];

                if (dist[u] != INT_MAX && dist[u] + price < temp[v]) {
                    temp[v] = dist[u] + price;
                }
            }
            dist = temp;
        }

        return dist[dst] == INT_MAX ? -1 : dist[dst];
    }
};