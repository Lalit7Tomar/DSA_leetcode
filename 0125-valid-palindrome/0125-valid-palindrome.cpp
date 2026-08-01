class Solution {
public:
    bool isPalindrome(string s) {
      
          for(int i=0;i<s.length();i++){
            if(64<int(s[i]) && int(s[i])<91){
                int y=int(s[i]);
                y=y+32;
                s[i]=char(y);
            }
        }
        // remove non useful character
       string temp;
       for(int i=0;i<s.length();i++){
        if(('a'<=s[i] && s[i]<='z') || ('0' <= s[i] && s[i] <= '9')){
            temp.push_back(s[i]);
        }
        else{
            continue;
        }
       }
       bool flag=true;
       for(int i=0;i<temp.size()/2;i++){
        if(temp[i]==temp[temp.size()-1-i]){
            continue;
        }
        else{
            flag=false;
        }
       }
       return flag;
       }

};