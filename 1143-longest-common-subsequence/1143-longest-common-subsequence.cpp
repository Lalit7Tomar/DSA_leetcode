class Solution {
public:
   
    int longestCommonSubsequence(string text1, string text2) {
        int size1=text1.size();
        int size2=text2.size();
        vector<vector<int>> matrix(text1.size()+1,vector<int>(text2.size()+1,0));
        int ind1=size1-1;
        int ind2=size2-1;
        /*
           matrix[0][ind2]=0; text1[-1:-1][-1:ind2-1];
           matrix[ind1][0]=0;


        */
       
        for(int i=1;i<matrix.size();i++){
            for(int j=1;j<matrix[0].size();j++){
                  if(text1[i-1]==text2[j-1]) matrix[i][j]=matrix[i-1][j-1]+1;
               else matrix[i][j]=max(matrix[i-1][j],matrix[i][j-1]);
               
            }
        }
        return matrix[ind1+1][ind2+1];
    }
};