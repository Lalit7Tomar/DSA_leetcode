class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        stack<int> s;
        vector<int> nextgreater(nums.size());
        if(nums.size()==0 || nums.size()==1){
            vector<int> a;
            a.push_back(-1);
            return a;
        }
        for(int i=nums.size()-2;i>=0;i--){
            s.push(nums[i]);
        }

        for(int i=nums.size()-1;i>=0;i--){
            if(s.top()<=nums[i]){
                while(!s.empty() && s.top()<=nums[i]){
                    s.pop();
                }
                if(s.empty()){
                    nextgreater[i]=-1;
                }
                else{
                    nextgreater[i]=s.top();
                }
              
            }
            else{
                nextgreater[i]=s.top();
            }
            s.push(nums[i]);
        }
        return nextgreater;
    }
};