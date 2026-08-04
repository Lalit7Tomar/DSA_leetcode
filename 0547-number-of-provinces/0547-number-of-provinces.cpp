class Solution {
public:
    void dfs(vector<vector<int>>& isConnected,set<int>& s,int src){
        
        s.insert(src);
        for(int i=0;i<isConnected.size();i++){
            if(i!=src && s.find(i)==s.end() && isConnected[src][i]==1){
                dfs(isConnected,s,i);
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        set<int> s;
        int ans=0;
        for(int i=0;i<isConnected.size();i++){
           if(s.find(i)==s.end()){
              s.insert(i);
              ans++;
              dfs(isConnected,s,i);
           }
        }
       return ans;
    }
};