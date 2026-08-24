class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
      if(piles.size()>h){
        return -1;
      }
      //maximum capacity=piles.max;
      int max=INT_MIN;
      for(int i=0;i<piles.size();i++){
        if(max<piles[i]){
            max=piles[i];
        }
       
      }
      int s=1;
      int e=max;
     if(piles.size()==1){
        if(piles[0]%h!=0){
        return piles[0]/h+1;
        }
        else{
            return piles[0]/h;
        }
     }
      int h1=e;
      int flag=0;
      while(s<=e){
          long long c=0;
           int mid=(s+e)/2;
          for(int i=0;i<piles.size();i++){
               c=c+(piles[i]+mid-1)/mid;
           }
            
            if(c==h){
                h1=min(mid,h1);
                e=mid-1;
            }
            else if(c<h){
                 h1=min(mid,h1);
                e=mid-1;
            }
            else if(c>h){
                s=mid+1;
            }
          

      }
      return h1;
    }
};