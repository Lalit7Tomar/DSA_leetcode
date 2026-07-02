class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        
         int i=0;
         int maxlen=0;
         int j=i+1;
          int len=1;
          if(s.length()==0){
            return 0;
          }
           unordered_set<int> st;
           st.insert(s[i]);
         while(j<s.length()){
            while( j<s.length() && st.find(s[j])==st.end()){
              st.insert(s[j]);
               j++;
                len++;
            }
              if(j>=s.length()-1){
                break;
              }
                if(len>maxlen){
                    maxlen=len;
                }
                while( i<j && s[i]!=s[j]){
                    st.erase(s[i]);
                    i++;
                    len--;                    
                }
                st.erase(s[i]);
                i=i+1;
                len--;
               
            }
            
         if(len>maxlen){
            maxlen=len;
         }
        return maxlen;
    }
};