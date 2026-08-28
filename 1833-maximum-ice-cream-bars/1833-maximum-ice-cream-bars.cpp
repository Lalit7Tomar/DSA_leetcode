class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        sort(costs.begin(),costs.begin()+costs.size());
        int n=0;
        for(int i=0;i<costs.size();i++){
            if(costs[i]<=coins){
                coins=coins-costs[i];
                n++;

            }
            else{
                break;
            }
        }
        return n;
    }
};