class Solution {
public:
    void dfs(vector<vector<int>>& adj,vector<int>& visited,int e){
        visited[e]=1;
       for(int i=0;i<adj[e].size();i++){
          if(!visited[adj[e][i]]){
            visited[adj[e][i]]=1;
            dfs(adj,visited,adj[e][i]);
          }        
       }
       return;
    }
    int makeConnected(int n, vector<vector<int>>& connections) {
     // if noof edges==n-1 and 
     if(connections.size()<n-1) return -1;
     // dfs traversal to explore all nodes
     vector<int> visited(n,0);
     vector<vector<int>> adj(n);
     for(int i=0;i<connections.size();i++){
        adj[connections[i][0]].push_back(connections[i][1]);
           adj[connections[i][1]].push_back(connections[i][0]);

     }  
     int count=0;
     for(int i=0;i<n;i++){ 
         if(visited[i]==0){
             dfs(adj,visited,i);
           count++;
     }}
    
     return count-1;
    }
};