class Solution {
public:
    
    
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
     // RTopological sort
     vector<int> indegree(numCourses);
      vector<vector<int>> adjacency_list(numCourses);

     for(int i=0;i<prerequisites.size();i++){
        indegree[prerequisites[i][0]]++;
        adjacency_list[prerequisites[i][1]].push_back(prerequisites[i][0]);
     }
     
    
     queue<int> q;
     vector<int> ans;
     set<int> s;
     for(int i=0;i<numCourses;i++){
        if(indegree[i]==0){
            q.push(i);
            s.insert(i);
        }
     }
     while(!q.empty()){
        int top=q.front();
        q.pop();
        ans.push_back(top);
        for(int i=0;i<adjacency_list[top].size();i++){
          if(indegree[adjacency_list[top][i]]==0 && s.find(adjacency_list[top][i])!=s.end()){
            continue;
          }
           if(indegree[adjacency_list[top][i]]==1){
            indegree[adjacency_list[top][i]]--;
             s.insert(adjacency_list[top][i]);
             q.push(adjacency_list[top][i]);
           }
          else if(indegree[adjacency_list[top][i]]>1){
             indegree[adjacency_list[top][i]]--;
          }
        }
     }
     if(ans.size()!=numCourses){
        return {};
     }
     return ans;
    }
};