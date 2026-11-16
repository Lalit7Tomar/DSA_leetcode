class Solution {
public:
    int wateringPlants(vector<int>& plants, int capacity) {
        int total=0;
        int t=capacity;
        if(plants.size()==0) return 0;
        for(int i=0;i<plants.size();i++){
            if(t<plants[i]){
                total=total+2*(i)+1;
                t=capacity-plants[i];
                
            }
            else{
                total++;
                t=t-plants[i];
            } 
        }
        return total;
    }
};