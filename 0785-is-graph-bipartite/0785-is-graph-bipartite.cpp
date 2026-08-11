class Solution {
public:
   
    bool isBipartite(vector<vector<int>>& graph) {
      // dfs
       queue<int> q;
        vector<int> color(graph.size(),-1);
      
    
     for(int i=0;i<graph.size();i++){
            if(color[i]==-1){
                q.push(i);
                color[i]=0;
                while(!q.empty()){
                    int top=q.front();
                    q.pop();
                    for(int j=0;j<graph[top].size();j++){
                        if(color[graph[top][j]]==-1){
                            if(color[top]==0){
                            color[graph[top][j]]=1;
                            q.push(graph[top][j]);
                            }
                            else{
                             color[graph[top][j]]=0;
                               q.push(graph[top][j]);

                            }
                        }
                        if(color[graph[top][j]]!=-1 && color[graph[top][j]]==color[top]){
                            return false;
                        }
                    }
                }
            }
        }
        return true;
}
};