class Solution {
public:
    vector<bool> checkArithmeticSubarrays(vector<int>& nums, vector<int>& l, vector<int>& r) {
        vector<bool> an;
        for(int i=0;i<l.size();i++){
           vector<int> a;
           for(int j=l[i];j<=r[i];j++){
            a.push_back(nums[j]);
           }
           sort(a.begin(),a.end());
           bool ans=true;
           int diff=0;
           if(a.size()>1) diff=a[1]-a[0];
           for(int j=0;j<a.size()-1;j++){
             if(a.size()>1 && (a[j+1]-a[j])!=diff){
              ans=false;
              break;
             }
           }
           an.push_back(ans);
        }
        return an;
    }
};