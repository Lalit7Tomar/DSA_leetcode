class Solution {
public:
    int numEnclaves(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        queue<pair<int, int>> q;

        for (int i = 0; i < m; ++i) {
            if (grid[i][0] == 1) { q.push({i, 0}); grid[i][0] = 0; }
            if (grid[i][n - 1] == 1) { q.push({i, n - 1}); grid[i][n - 1] = 0; }
        }
        for (int j = 0; j < n; ++j) {
            if (grid[0][j] == 1) { q.push({0, j}); grid[0][j] = 0; }
            if (grid[m - 1][j] == 1) { q.push({m - 1, j}); grid[m - 1][j] = 0; }
        }

        vector<pair<int, int>> dirs = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        while (!q.empty()) {
            auto [r, c] = q.front();
            q.pop();

            for (auto& dir : dirs) {
                int nr = r + dir.first;
                int nc = c + dir.second;

                if (nr >= 0 && nr < m && nc >= 0 && nc < n && grid[nr][nc] == 1) {
                    grid[nr][nc] = 0; 
                    q.push({nr, nc});
                }
            }
        }

        int enclave_count = 0;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 1) {
                    enclave_count++;
                }
            }
        }

        return enclave_count;
    }
};