class Solution {
public:
   // dfs traveral starting from all nodes
   /*
     set of safe node
     dfs(0)->dfs(1),df2(2).
     dfs(1)->dfs(2),dfs(3),
     dfs(2)->dfs(5)->return true; 2 is safe node
     dfs(3)

   */
    set<int> safenode;
    bool dfs(vector<vector<int>>& graph,int i,vector<int>& visited){
        if(graph[i].size()==0) return true;
        int a=0;
        visited[i]=1;
       for(int j=0;j<graph[i].size();j++){
               if(safenode.find(graph[i][j])!=safenode.end()){
                 a++;
                                }
          if(safenode.find(graph[i][j])==safenode.end() && visited[graph[i][j]]==0 ){
            if(dfs(graph,graph[i][j],visited)) a++;
           
       }
       }
       if(a==graph[i].size()){
        
        safenode.insert(i);
        return true;
       }
      
         return false;
    }
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
       // calculate targetnodes
       for(int i=0;i<graph.size();i++){
        if(graph[i].size()==0) safenode.insert(i);
       }
           vector<int> visited(graph.size());

       for(int i=0;i<graph.size();i++){
          if(safenode.find(i)==safenode.end() && visited[i]==0){
            visited[i]=1;
            dfs(graph,i,visited);
          }}
          vector<int> ans;
            for(auto it=safenode.begin();it!=safenode.end();it++){
                ans.push_back(*it);
            }
            return ans;
    }
};