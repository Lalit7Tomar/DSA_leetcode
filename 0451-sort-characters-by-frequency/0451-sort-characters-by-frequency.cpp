class Solution {
public:
    string frequencySort(string s) {
          priority_queue<pair<int, char>> c;
        unordered_map<char,int> m;
        for(int i=0;i<s.length();i++){
            m[s[i]]++;
        }
        for(auto &p:m){
            pair<int,char> pq;
            pq.first=p.second;
            pq.second=p.first;
            c.push(pq);
        }
        string ans;
        while(!c.empty()){
            pair<int,char> a=c.top();
            for(int i=0;i<a.first;i++){
            ans.push_back(a.second);
            }
            c.pop();
        }
        return ans;
    }
};