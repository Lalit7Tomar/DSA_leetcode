class Solution {
public:
    vector<string> largestString(vector<int>& nums) {
       vector<string> ans;
       for(int x:nums){
    
           int pos=0;
           string s="";
           while(x>0){
           int p=1;
               while(p<=x/2 && pos<25){
                   p=p*2;
                   pos++;
               }
               x=x-p;
               s=s+char('a'+pos);
               pos=0;
       }
       ans.push_back(s);
       }
        return ans;
    }
};