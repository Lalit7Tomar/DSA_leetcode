class Solution {
public:
    bool helper(string s,stack<char>& st,int i) {
         if (i == s.size()) {
        return st.empty();
    }

    char c = s[i];
    if (c == '(' || c == '{' || c == '[') {
        st.push(c);
    } else {
        if (s.empty()) return false;

        char top = st.top();
        if ((c == ')' && top != '(') ||
            (c == '}' && top != '{') ||
            (c == ']' && top != '['))
            return false;

        st.pop();
    }

    return helper(s, st, i + 1);
}

bool isValid(string s) {
    if (s.size() % 2 != 0) return false;
    stack<char> st;
    return helper(s, st, 0);
    }
};