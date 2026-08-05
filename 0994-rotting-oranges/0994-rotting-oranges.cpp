class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        
        queue<pair<int, int>> q;
        int fresh_oranges = 0;
        
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 2) {
                    q.push({i, j});
                } else if (grid[i][j] == 1) {
                    fresh_oranges++;
                }
            }
        }
        
        int minutes = 0;
        vector<pair<int, int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}}; 
        
        while (!q.empty() && fresh_oranges > 0) {
            int size = q.size();
            
            for (int i = 0; i < size; i++) {
                pair<int, int> p = q.front();
                q.pop();
                
                int r = p.first;
                int c = p.second;
                
                for (auto d : directions) {
                    int nr = r + d.first;
                    int nc = c + d.second;
                    
                    if (nr >= 0 && nr < m && nc >= 0 && nc < n && grid[nr][nc] == 1) {
                        grid[nr][nc] = 2; 
                        q.push({nr, nc});
                        fresh_oranges--;
                    }
                }
            }
            minutes++; 
        }
        
        return fresh_oranges == 0 ? minutes : -1;
    }
};