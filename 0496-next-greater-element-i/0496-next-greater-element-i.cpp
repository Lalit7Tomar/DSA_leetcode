class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
       // solving
       vector<int> nextgreater(nums2.size());
       stack<int> s;
       for(int i=nums2.size()-1;i>=0;i--){
         if(i==nums2.size()-1){
            nextgreater[i]=-1;
            s.push(nums2[i]);
         }
         else{
            if(s.top()<=nums2[i]){
                while(!s.empty() && s.top()<=nums2[i]){
                    s.pop();
                }
                if(s.empty()){
                    nextgreater[i]=-1;
                }
                else{
                    nextgreater[i]=s.top();
                }
                s.push(nums2[i]);
            }
            else{
                nextgreater[i]=s.top();
                s.push(nums2[i]);
            }
         }

       }
       vector<int> nextgreater1(nums1.size());
       for(int i=0;i<nums1.size();i++){
        for(int j=0;j<nums2.size();j++){
            if(nums1[i]==nums2[j]){
                nextgreater1[i]=nextgreater[j];
            }
        }
       }
       return nextgreater1;
    }
};