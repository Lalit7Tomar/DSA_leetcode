class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
     int fivecount=0;
     int tencount=0;
     int i=0;
     while(i<bills.size()){
        if(bills[i]==5) fivecount++;
        else if(bills[i]==10){
            if(fivecount==0) return false;
            fivecount--;
            tencount++;
        }
        else if(bills[i]==20){
            if(tencount==0){
                if(fivecount<3) return false;
                fivecount=fivecount-3;

            }
            if(tencount>0){
                tencount--;
                if(fivecount==0) return false;
                fivecount--;
            }
        }
        i++;
     }
     return true;
    }
};