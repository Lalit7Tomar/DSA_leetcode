class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
       unordered_map<int,int> m;
     int sum=0;
     m[sum]=1;
     int c=0;
     for(int i=0;i<nums.size();i++){
        sum=sum+nums[i];
        
        
            auto it=m.find(sum-k);
            if(it!=m.end()){
               c=c+it->second;
            }
    
        auto it1=m.find(sum);
        if(it1!=m.end()){
            it1->second++;
        }
        else if(it1==m.end()){
            m[sum]=1;

        }

     }
     return c;
  
    }
};