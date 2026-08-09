class Solution {
public:
    void solve(vector<vector<char>>& board) {
       set<pair<int,int>> s;
       queue<pair<int,int>> q;
       for(int i=0;i<board[0].size();i++){
        if(board[0][i]=='O' && s.find({0,i})==s.end()){
            s.insert({0,i});
            q.push({0,i});
            while(!q.empty()){
              pair<int,int> p=q.front();
              q.pop();
              if(p.first-1>=0 && s.find({p.first-1,p.second})==s.end() && board[p.first-1][p.second]=='O'){
                 s.insert({p.first-1,p.second});
                 q.push({p.first-1,p.second});
              } 
               if(p.first+1<board.size() && s.find({p.first+1,p.second})==s.end() && board[p.first+1][p.second]=='O'){
                 s.insert({p.first+1,p.second});
                 q.push({p.first+1,p.second});
              }
              if(p.second-1>=0 && s.find({p.first,p.second-1})==s.end() && board[p.first][p.second-1]=='O'){
                 s.insert({p.first,p.second-1});
                 q.push({p.first,p.second-1});
              } 
               if(p.second+1<board[0].size() && s.find({p.first,p.second+1})==s.end() && board[p.first][p.second+1]=='O'){
                 s.insert({p.first,p.second+1});
                 q.push({p.first,p.second+1});
              }
              
            }
        }}
         for(int i=0;i<board[0].size();i++){
        if(board[board.size()-1][i]=='O' && s.find({board.size()-1,i})==s.end()){
            s.insert({board.size()-1,i});
            q.push({board.size()-1,i});
            while(!q.empty()){
              pair<int,int> p=q.front();
              q.pop();
              if(p.first-1>=0 && s.find({p.first-1,p.second})==s.end() && board[p.first-1][p.second]=='O'){
                 s.insert({p.first-1,p.second});
                 q.push({p.first-1,p.second});
              } 
               if(p.first+1<board.size() && s.find({p.first+1,p.second})==s.end() && board[p.first+1][p.second]=='O'){
                 s.insert({p.first+1,p.second});
                 q.push({p.first+1,p.second});
              }
              if(p.second-1>=0 && s.find({p.first,p.second-1})==s.end() && board[p.first][p.second-1]=='O'){
                 s.insert({p.first,p.second-1});
                 q.push({p.first,p.second-1});
              } 
               if(p.second+1<board[0].size() && s.find({p.first,p.second+1})==s.end() && board[p.first][p.second+1]=='O'){
                 s.insert({p.first,p.second+1});
                 q.push({p.first,p.second+1});
              }
              
            }
        }
       } 
        for(int i=0;i<board.size();i++){
        if(board[i][0]=='O' && s.find({i,0})==s.end()){
            s.insert({i,0});
            q.push({i,0});
            while(!q.empty()){
              pair<int,int> p=q.front();
              q.pop();
              if(p.first-1>=0 && s.find({p.first-1,p.second})==s.end() && board[p.first-1][p.second]=='O'){
                 s.insert({p.first-1,p.second});
                 q.push({p.first-1,p.second});
              } 
               if(p.first+1<board.size() && s.find({p.first+1,p.second})==s.end() && board[p.first+1][p.second]=='O'){
                 s.insert({p.first+1,p.second});
                 q.push({p.first+1,p.second});
              }
              if(p.second-1>=0 && s.find({p.first,p.second-1})==s.end() && board[p.first][p.second-1]=='O'){
                 s.insert({p.first,p.second-1});
                 q.push({p.first,p.second-1});
              } 
               if(p.second+1<board[0].size() && s.find({p.first,p.second+1})==s.end() && board[p.first][p.second+1]=='O'){
                 s.insert({p.first,p.second+1});
                 q.push({p.first,p.second+1});
              }
              
            }
        }}
        for(int i=0;i<board.size();i++){
        if(board[i][board[0].size()-1]=='O' && s.find({i,board[0].size()-1})==s.end()){
            s.insert({i,board[0].size()-1});
            q.push({i,board[0].size()-1});
            while(!q.empty()){
              pair<int,int> p=q.front();
              q.pop();
              if(p.first-1>=0 && s.find({p.first-1,p.second})==s.end() && board[p.first-1][p.second]=='O'){
                 s.insert({p.first-1,p.second});
                 q.push({p.first-1,p.second});
              } 
               if(p.first+1<board.size() && s.find({p.first+1,p.second})==s.end() && board[p.first+1][p.second]=='O'){
                 s.insert({p.first+1,p.second});
                 q.push({p.first+1,p.second});
              }
              if(p.second-1>=0 && s.find({p.first,p.second-1})==s.end() && board[p.first][p.second-1]=='O'){
                 s.insert({p.first,p.second-1});
                 q.push({p.first,p.second-1});
              } 
               if(p.second+1<board[0].size() && s.find({p.first,p.second+1})==s.end() && board[p.first][p.second+1]=='O'){
                 s.insert({p.first,p.second+1});
                 q.push({p.first,p.second+1});
              }
              
            }
        }}
        for(int i=0;i<board.size();i++){
            for(int j=0;j<board[0].size();j++){
                if(board[i][j]=='O' && s.find({i,j})==s.end()){
                    board[i][j]='X';
                }
            }
        }
        return;
    }
};