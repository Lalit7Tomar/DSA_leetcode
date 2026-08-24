class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> pcount(26);
        vector<int> scount(26);
        int i=0;
        int j=0;
        vector<int> ans;
        if(p.length()>s.length()) return {};
        for(int i=0;i<p.length();i++){
            pcount[p[i]-'a']++;
            scount[s[i]-'a']++;
        }
        if(pcount==scount) ans.push_back(i);
        for(i=p.length();i<s.length();i++){
            scount[s[i]-'a']++;
            scount[s[i-p.length()]-'a']--;
            if(scount==pcount) ans.push_back(i-p.length()+1);
        }
        return ans;
    }
};