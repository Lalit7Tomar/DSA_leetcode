class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(),g.begin()+g.size());
        sort(s.begin(),s.begin()+s.size());
        int i=0;
        int j=0;
        int count=0;
        while(i<g.size() && j<s.size()){
            while(j<s.size() && s[j]<g[i]) j++;
            if(j<s.size()) count++;
            i++;
            j++;
        }
        return count;
    }
};