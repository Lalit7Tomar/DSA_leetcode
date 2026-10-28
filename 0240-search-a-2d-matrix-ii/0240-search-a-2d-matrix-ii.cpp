class Solution {
public:
  
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int rows=matrix.size()-1;
        int columns=matrix[0].size()-1;
        int r=0;
        int c=columns;
        while(r<=rows && c>=0){
            if(matrix[r][c]==target) return true;
            else if(matrix[r][c]>target){
                c--;
            }
            else{
                r++;
            }
        }
        return false;      
     }
};