class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int stcolor=image[sr][sc];
        if(stcolor==color) return image;
        queue<pair<int,int>> q;
        q.push({sr,sc});
        image[sr][sc]=color;
        while(!q.empty()){
           pair<int,int> p=q.front();
           q.pop();
           if(p.first-1>=0 && p.first-1<image.size() && p.second>=0 && p.second<image[0].size() && image[p.first-1][p.second]==stcolor){
               image[p.first-1][p.second]=color;
               q.push({p.first-1,p.second});
           }
          if(p.first+1>=0 && p.first+1<image.size() && p.second>=0 && p.second<image[0].size() && image[p.first+1][p.second]==stcolor){
               image[p.first+1][p.second]=color;
               q.push({p.first+1,p.second});
           }
            if(p.first>=0 && p.first<image.size() && p.second-1>=0 && p.second-1<image[0].size() && image[p.first][p.second-1]==stcolor){
               image[p.first][p.second-1]=color;
               q.push({p.first,p.second-1});
           }
          if(p.first>=0 && p.first<image.size() && p.second+1>=0 && p.second+1<image[0].size() && image[p.first][p.second+1]==stcolor){
               image[p.first][p.second+1]=color;
               q.push({p.first,p.second+1});
           }}
         
         return image;
        }
    
};