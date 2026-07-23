class Solution {
public:
    int characterReplacement(string s, int k) {
        // 
        set<char> se;
        for(int i=0;i<s.length();i++){
            se.insert(s[i]);
        }
        int maxlen=0;
        for(char target:se){
         
          int left=0,right=0;
          int oddelement=0;
          while(right<s.length()){
            if(s[right]!=target){
                oddelement++;
            }
            while(oddelement>k){
                if(s[left]==target){
                    left++;
                }
                else{
                    left++;
                    oddelement--;
                }
            }
            maxlen=max(maxlen,right+1-left);
            right++;
          }
        }
        return maxlen;
    }
};