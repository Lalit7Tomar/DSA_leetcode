class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        if(hand.size()%groupSize!=0) return false;
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        unordered_map<int,int> m;
        for(int i=0;i<hand.size();i++){
            m[hand[i]]++;
        }
        for(auto it=m.begin();it!=m.end();it++){
         pq.push({it->first,it->second});
         
        }
        while(!pq.empty()){
            pair<int,int> p=pq.top();
            int curr=p.first;
            p.second--;
            priority_queue<pair<int,int>> temp;
            pq.pop();
            if(p.second>0)   temp.push(p);
            for(int i=0;i<groupSize-1;i++){
                if(pq.top().first!=p.first+1) return false;
                p=pq.top();
                p.second--;
                if(p.second>0) temp.push(p);
                pq.pop();
            }
            while(!temp.empty()){
                 pq.push(temp.top());
                 temp.pop();

            }
        }
        return true;
    }
};