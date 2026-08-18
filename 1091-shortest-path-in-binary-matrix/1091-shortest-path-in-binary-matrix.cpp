class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        queue<pair<pair<int,int>,int>> q;
        set<pair<int,int>> s;
        if(grid[0][0]!=0 || grid[grid.size()-1][grid[0].size()-1]!=0){
           return -1;
        }
        int l=1;
        q.push({{0,0},1});
        s.insert({0,0});
        while(!q.empty()){
            pair<pair<int,int>,int> top=q.front();
            q.pop();
            l=top.second;
            if(top.first.first==grid.size()-1 && top.first.second==grid[0].size()-1){
                return l;
            }
             if(top.first.first+1<grid.size() && top.first.second-1>=0 && s.find({top.first.first+1,top.first.second-1})==s.end() && grid[top.first.first+1][top.first.second-1]==0){
                q.push({{top.first.first+1,top.first.second-1},l+1});
                s.insert({top.first.first+1,top.first.second-1});
             }
              if(top.first.first+1<grid.size() && top.first.second+1<grid[0].size() && s.find({top.first.first+1,top.first.second+1})==s.end() && grid[top.first.first+1][top.first.second+1]==0){
                q.push({{top.first.first+1,top.first.second+1},l+1});
                s.insert({top.first.first+1,top.first.second+1});

            }
            if(top.first.first-1>=0 && top.first.second-1>=0 && s.find({top.first.first-1,top.first.second-1})==s.end() && grid[top.first.first-1][top.first.second-1]==0){
                q.push({{top.first.first-1,top.first.second-1},l+1});
                                s.insert({top.first.first-1,top.first.second-1});

            }
             if(top.first.first-1>=0 && top.first.second+1<grid[0].size() && s.find({top.first.first-1,top.first.second+1})==s.end() && grid[top.first.first-1][top.first.second+1]==0){
                q.push({{top.first.first-1,top.first.second+1},l+1});
                s.insert({top.first.first-1,top.first.second+1});

            }
             if(top.first.first-1>=0 && top.first.second>=0 && s.find({top.first.first-1,top.first.second})==s.end() && grid[top.first.first-1][top.first.second]==0){
                q.push({{top.first.first-1,top.first.second},l+1});
                                s.insert({top.first.first-1,top.first.second});

            }
            
             if(top.first.first>=0 && top.first.second-1>=0 && s.find({top.first.first,top.first.second-1})==s.end() && grid[top.first.first][top.first.second-1]==0){
                q.push({{top.first.first,top.first.second-1},l+1});
                s.insert({top.first.first,top.first.second-1});

            }
             if(top.first.first>=0 && top.first.second+1<grid[0].size() && s.find({top.first.first,top.first.second+1})==s.end() && grid[top.first.first][top.first.second+1]==0){
                q.push({{top.first.first,top.first.second+1},l+1});
                s.insert({top.first.first,top.first.second+1});

            }
            
            
             if(top.first.first+1<grid.size() && top.first.second>=0 && s.find({top.first.first+1,top.first.second})==s.end() && grid[top.first.first+1][top.first.second]==0){
                q.push({{top.first.first+1,top.first.second},l+1});
                s.insert({top.first.first+1,top.first.second});

            }
            
        }   
          return -1;
    }
};