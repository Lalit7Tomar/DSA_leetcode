class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
       set<int> s;
      for(int i=0;i<nums.size();i++){
        s.insert(nums[i]);
      }
      int maxlen=0;
     
      for(int i: s){
        int len=1;
        if(s.find(i-1)==s.end()){
            int curr=i;
            while(s.find(curr+1)!=s.end()){
                curr++;
                len++;
            }
            if(maxlen<len){
                maxlen=len;
            }
        }
      
    }
    return maxlen;  
    }
};