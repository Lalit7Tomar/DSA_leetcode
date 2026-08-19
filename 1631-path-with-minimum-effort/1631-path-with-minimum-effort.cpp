class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
     int rows = heights.size();
        int cols = heights[0].size();
        priority_queue<pair<int, pair<int, int>>, 
                       vector<pair<int, pair<int, int>>>, 
                       greater<pair<int, pair<int, int>>>> pq;
        vector<vector<int>> dist(rows, vector<int>(cols, INT_MAX));

        dist[0][0] = 0;
        pq.push({0, {0, 0}});

        int dr[] = {-1, 1, 0, 0};
        int dc[] = {0, 0, -1, 1};

        while (!pq.empty()) {
            auto [effort, cell] = pq.top();
            auto [r, c] = cell;
            pq.pop();
            if (r == rows - 1 && c == cols - 1) {
                return effort;
            }
            if (effort > dist[r][c]) continue;

            for (int i = 0; i < 4; ++i) {
                int nr = r + dr[i];
                int nc = c + dc[i];
                if (nr >= 0 && nr < rows && nc >= 0 && nc < cols) {
                    int nextEffort = max(effort, abs(heights[r][c] - heights[nr][nc]));
                    if (nextEffort < dist[nr][nc]) {
                        dist[nr][nc] = nextEffort;
                        pq.push({nextEffort, {nr, nc}});
                    }
                }
            }
        }
        return 0;
    }
};