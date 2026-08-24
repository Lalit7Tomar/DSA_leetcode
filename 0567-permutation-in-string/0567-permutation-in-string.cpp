class Solution {
public:
    bool checkInclusion(string s1, string s2) {
       vector<int> s1count(26);
       vector<int> s2count(26);
              if(s2.length()<s1.length()) return false;

       for(int i=0;i<s1.length();i++){
        s1count[s1[i]-'a']++;
        s2count[s2[i]-'a']++;
          
       }
       if(s1count==s2count) return true;
       for(int i=s1.length();i<s2.length();i++){
           s2count[s2[i]-'a']++;
           s2count[s2[i-s1.length()]-'a']--;
           if(s1count==s2count) return true;
       }
       return false;
    }
    
};