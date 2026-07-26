class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
      string ans;
         int a=strs[0].length();
         for(int i=0;i<a;i++){
            char z=strs[0][i];
            int flag=0;
            for(int j=0;j<strs.size();j++){
                if(strs[j][i]==z){
                    continue;
                }
                else{
                    flag=1;
                    break;
                }}
                  if(flag==1){
                    break;
                  }
                  else{
                    ans.push_back(z);
                  }
            }
           
         
        return ans;  
    }
};