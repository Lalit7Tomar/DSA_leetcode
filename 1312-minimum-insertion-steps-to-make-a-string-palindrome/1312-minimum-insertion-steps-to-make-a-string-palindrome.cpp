class Solution {
public:
    int minInsertions(string s) {
       // calculate longest palindromic subsequence and subtract it from string length,divide ans/2
        string a=s;
        reverse(a.begin(),a.end());
        //
        int ind1=s.length()-1;
        int ind2=a.length()-1;
        vector<vector<int>> dp(s.length()+1,vector<int>(a.length()+1,0));
        for(int i=1;i<dp.size();i++){
            for(int j=1;j<dp[i].size();j++){
              dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
              if(s[i-1]==a[j-1]) dp[i][j]=1+dp[i-1][j-1];
            }
        }
         int x=s.length()-dp[ind1+1][ind2+1]; 
         
         return x;
    }
};