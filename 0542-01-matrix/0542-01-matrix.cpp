class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        // bfs
        queue<pair<pair<int,int>,int>> q;
        vector<vector<int>> pq(mat.size(),vector<int>(mat[0].size(),0));
        vector<vector<int>> v(mat.size(),vector<int>(mat[0].size(),0));
        for(int i=0;i<mat.size();i++){
            for(int j=0;j<mat[i].size();j++){
                if(mat[i][j]==0){
                   pq[i][j]=1;
                   q.push({{i,j},0});
                   v[i][j]=0;
                }
            }
        }
        while(!q.empty()){
            pair<pair<int,int>,int> p=q.front();
            q.pop();
            v[p.first.first][p.first.second]=p.second;
            if(p.first.first-1>=0 && p.first.first-1<mat.size() && pq[p.first.first-1][p.first.second]==0){
                q.push({{p.first.first-1,p.first.second},p.second+1});
                pq[p.first.first-1][p.first.second]=1;
            }
            if(p.first.first+1>=0 && p.first.first+1<mat.size() && pq[p.first.first+1][p.first.second]==0){
                q.push({{p.first.first+1,p.first.second},p.second+1});
                pq[p.first.first+1][p.first.second]=1;
            }
             if(p.first.second-1>=0 && p.first.second-1<mat[0].size() && pq[p.first.first][p.first.second-1]==0){
                q.push({{p.first.first,p.first.second-1},p.second+1});
                pq[p.first.first][p.first.second-1]=1;

            }
            if(p.first.second+1>=0 && p.first.second+1<mat[0].size() && pq[p.first.first][p.first.second+1]==0){
                q.push({{p.first.first,p.first.second+1},p.second+1});
                pq[p.first.first][p.first.second+1]=1;
            }
            
            
            
            
             }
             return v;
    }
};