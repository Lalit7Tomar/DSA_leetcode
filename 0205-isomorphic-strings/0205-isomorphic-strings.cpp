class Solution {
public:
    bool isIsomorphic(string s, string t) {
         unordered_map<char,char> m;
       unordered_map<char,char> m1;
       if(s.length()!=t.length()){
        return false;
       }
       
       for(int i=0;i<s.length();i++){
           if(m.find(s[i])!=m.end()){
            auto it=m.find(s[i]);
            if(it->second!=t[i]){
                return false;
            }

           }
           if(m1.find(t[i])!=m1.end()){
            auto it =m1.find(t[i]);
            if(it->second!=s[i]){
               return false;
            }
           }
           else{
            m[s[i]]=t[i];
            m1[t[i]]=s[i];
           }
       }
       return true;
    }
};