class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int ans=0;
        set<pair<int,int>> s;
        for(int i=0;i<grid.size();i++){
           for(int j=0;j<grid[i].size();j++){
            if(grid[i][j]=='1' && s.find({i,j})==s.end()){
                s.insert({
                    i,j
                });
                                ans=ans+1;

                queue<pair<int,int>> q;
                q.push({i,j});
                while(!q.empty()){
                    pair<int,int> p=q.front();
                    q.pop();
                    if(p.first-1>=0 && grid[p.first-1][p.second]=='1' && s.find({p.first-1,p.second})==s.end()){
                        grid[p.first][p.second]='1';
                        s.insert({p.first-1,p.second});
                        q.push({p.first-1,p.second});

                    }
                    if(p.first+1<grid.size() && grid[p.first+1][p.second]=='1' && s.find({p.first+1,p.second})==s.end()){
                        grid[p.first+1][p.second]='1';
                        s.insert({p.first+1,p.second});
                        q.push({p.first+1,p.second});
                    }
                    if(p.second-1>=0 && grid[p.first][p.second-1]=='1' && s.find({p.first,p.second-1})==s.end()){
                        grid[p.first][p.second-1]='1';
                           s.insert({p.first,p.second-1});
                           q.push({p.first,p.second-1});
                    }
                    if(p.second+1<grid[0].size() && grid[p.first][p.second+1]=='1' && s.find({p.first,p.second+1})==s.end()){
                        grid[p.first][p.second+1]='1';
                        s.insert({p.first,p.second+1});
                        q.push({p.first,p.second+1});
                    }
                }
            }
           }
        }
        return ans;
    }
};