class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int noofplant=0;
        int i=0;
        if(flowerbed.size()==1 && flowerbed[0]==0){
            if(n<=1) return true;
            else{
                return false;
            }
        }
        while(i<flowerbed.size()){
            while(i<flowerbed.size() && flowerbed[i]==1) i++;
            int j=i;
            while(j<flowerbed.size() && flowerbed[j]==0) j++;
           
            if(i==0 && j==flowerbed.size()) noofplant+=(j-i+1)/2;
            else  if(i==0 || j==flowerbed.size()) noofplant+=(j-i)/2;
            else{
                 noofplant+=(j-i-1)/2;
            }
            i=j;
        }
        if(noofplant>=n) return true;
        return false;
    }
};