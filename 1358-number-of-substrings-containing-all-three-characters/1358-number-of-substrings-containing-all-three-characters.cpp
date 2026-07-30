class Solution {
public:
    int numberOfSubstrings(string s) {
        int a=0;
        int b=0;
        int c=0;
        int ans=0;
        int i=0;
        int j=0;
        while(i<s.length()-2){
            while(j<s.length() && (!a || !b || !c)){
                if(s[j]=='a'){
                   a++; 
               }
               else if(s[j]=='b'){
                b++;
               } 
               else{
                c++;
               }
               j++;
           }
           
           if(a && b && c){
           ans=ans+s.length()-j+1;
           }
           if(s[i]=='a'){
            a--;
           }
           else if(s[i]=='b'){
            b--;
           }
           else{
            c--;
           }
           i++;
        }
        return ans;
    }
};