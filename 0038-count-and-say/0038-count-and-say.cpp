class Solution {
public:
    string countAndSay(int n) {
        unordered_map<int,string> m;
        m[1]="1";
        for(int i=2;i<=n;i++){
            string s=m[i-1];
            // calculate rle
            string rle="";
            for(int k=0;k<s.length();k++){
                int j=k;
                while(k+1<s.length() && s[k]==s[k+1]) k++;
                int l=k-j+1;
                rle=rle+to_string(l)+s[j];
                
            }
            m[i]=rle;
        }
        return m[n];
    }
};