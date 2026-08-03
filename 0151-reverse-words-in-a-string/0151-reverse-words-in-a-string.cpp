class Solution {
public:
    string reverseWords(string s) {
         while (!s.empty() && s.front() == ' ') {
        s.erase(s.begin());
    }

    while (!s.empty() && s.back() == ' ') {
        s.pop_back();
    }
    int i=0;
     while(i<s.length()){
     if(s[i]==' ' && s[i+1]==' '){
        s.erase(i,1);
     }
     else{
        i++;
     }}
    
        int start=0;
        int end=s.length()-1; 
        while(start<end){
            char c=s[start];
            s[start]=s[end];
            s[end]=c;
            start++;
            end--;
        }
     // reverse each word
     int i1=0;
     int j1=0;
     while(j1<s.length()){
     while(j1<s.length() && s[j1]!=' ' ){
        j1++;
     }
     j1--;
     
     int k=j1;
     while(i1<j1){
        char c=s[i1];
        s[i1]=s[j1];
        s[j1]=c;
        i1++;
        j1--;
     }
     
     i1=k+2;
     j1=i1;
    
     if(j1>=s.length()-1){
        break;
     }
    }
    
    return s;
    }
};