class Solution {
public:
    int minAddToMakeValid(string s) {
        int noofmoves=0;
        stack<char> s1;
        s1.push(s[0]);
        for(int i=1;i<s.length();i++){
            if(!s1.empty() && s1.top()=='(' && s[i]==')'){
                s1.pop();
            }
            
            else {
                s1.push(s[i]);
            }
        }
        return s1.size();
    }
};