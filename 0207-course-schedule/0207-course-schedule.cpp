class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        //indegree
         vector<int> indegree(numCourses);
      vector<vector<int>> adjacency_list(numCourses);

     for(int i=0;i<prerequisites.size();i++){
        indegree[prerequisites[i][0]]++;
        adjacency_list[prerequisites[i][1]].push_back(prerequisites[i][0]);
     }
     vector<int> ans;
     queue<int> q;
     for(int i=0;i<indegree.size();i++){
        if(indegree[i]==0){
           q.push(i); 
        }
     }
     while(!q.empty()){
        int top=q.front();
        ans.push_back(top);
        q.pop();
        for(int i=0;i<adjacency_list[top].size();i++){
            if(indegree[adjacency_list[top][i]]>0){
             indegree[adjacency_list[top][i]]--;
             if(indegree[adjacency_list[top][i]]==0){
                q.push(adjacency_list[top][i]);
             }
            }
        }
     }
     if(ans.size()!=numCourses){
        return false;
     }
     return true;
    }
};