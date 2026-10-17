class Solution {
public:
    int minBitFlips(int start, int goal) {
        start=start^goal;
        int cnt=0;
        while(start!=0){
            if(start%2==1){
                cnt++;
            }
            start=start>>1;
        }
        return cnt;
    }
};