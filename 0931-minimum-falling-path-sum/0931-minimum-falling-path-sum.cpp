class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
         vector<int> prev = matrix[0];
        vector<int> curr(n);

        for (int i = 1; i < m; i++) {
            for (int j = 0; j < n; j++) {
                int left  = (j > 0)     ? prev[j-1] : INT_MAX;
                int right = (j+1 < n)   ? prev[j+1] : INT_MAX;
                int top   = prev[j];

                curr[j] = matrix[i][j] + min({left, right, top});
            }
            prev = curr;  
        }

        return *min_element(prev.begin(), prev.end());
    }
};
