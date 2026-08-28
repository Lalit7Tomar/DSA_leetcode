class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
       //  2 priority_queue bananunga
       priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> min;
       for(int i=0;i<profits.size();i++){
         min.push({capital[i],profits[i]});
       }
       if(min.top().first>w) return w;
       priority_queue<pair<int,int>> max;
       max.push({min.top().second,min.top().first});
       min.pop();
       int it=0;
       int c=w;
       while(it<k){
           pair<int,int> p={0,0};
           while(!min.empty() && min.top().first<=c){
            max.push({min.top().second,min.top().first});
             min.pop();
           }
            if(max.empty()) break;  
            c=c+max.top().first;
            max.pop();
           
          
            it++;
       }
       return c;
    }
};