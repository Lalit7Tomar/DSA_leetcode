class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int mx=0;
        for(int i=0;i<piles.size();i++){
            mx=max(piles[i],mx);
                    }
       long long low=1;
       long long ans=mx;
       long long s=1;
       long long e=mx;
       while(s<=e){
         long long mid=s+(e-s)/2;
         long long hourcount=0;
        for(int i=0;i<piles.size();i++){
            hourcount+=piles[i]/mid;
            if(piles[i]%mid!=0) hourcount++;
        }
        if(hourcount==h){
             ans=min(ans,mid);
             e=mid-1;
       }
        else if(hourcount>h){
            s=mid+1;
        }
        else if(hourcount<h){
            e=mid-1;
            ans = min(ans, mid);
        }
      }
      return ans;
    }
};