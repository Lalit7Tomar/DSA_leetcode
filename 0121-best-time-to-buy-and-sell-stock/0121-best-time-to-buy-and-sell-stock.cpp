class Solution {
public:
    int maxProfit(vector<int>& prices) {
         stack<int> s;
        vector<int> ans(prices.size());
        s.push(INT_MIN);
        for(int i=prices.size()-1;i>=0;i--){
            
            if(s.top()>prices[i]){
                ans[i]=s.top()-prices[i];
            }
            else{
               ans[i]=0;
               s.push(prices[i]);
            }
        }
        int max=INT_MIN;
        for(int i=0;i<ans.size();i++){
            if(ans[i]>max){
                max=ans[i];
            }
        }
        return max;
    }
};