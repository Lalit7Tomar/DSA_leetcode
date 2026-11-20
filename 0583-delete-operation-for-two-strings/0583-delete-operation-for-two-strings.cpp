class Solution {
public:
    int minDistance(string word1, string word2) {
       // calculate longest common subsequence and 
       // base case
       vector<vector<int>> matrix(word1.size()+1,vector<int>(word2.size()+1,0));
       for(int i=1;i<matrix.size();i++){
        for(int j=1;j<matrix[i].size();j++){
            if(word1[i-1]==word2[j-1]){
                matrix[i][j]+=matrix[i-1][j-1]+1;
            } 
            else{
                matrix[i][j]=max(matrix[i][j-1],matrix[i-1][j]);
            }

        }
       }
       int n=matrix[word1.size()][word2.size()];
       return word1.size()+word2.size()-2*n;
    }
};