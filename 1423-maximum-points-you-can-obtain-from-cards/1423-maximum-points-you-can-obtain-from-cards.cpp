class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int minsum=0;
        int i=0;
        int j=cardPoints.size()-k-1;
        int sum=0;
        for(int x=0;x<cardPoints.size()-k;x++){
            minsum=minsum+cardPoints[x];
           sum=sum+cardPoints[x];

        }
        j++;
        while(j<cardPoints.size()){
          if(sum<minsum){
            minsum=sum;
          }
          sum=sum-cardPoints[i];
          i++;
          sum=sum+cardPoints[j];
          j++;
        }
        if(sum<minsum){
            minsum=sum;
        }
        int arrsum=0;
        for(int t=0;t<cardPoints.size();t++){
           arrsum=arrsum+cardPoints[t];
        }
        return arrsum-minsum;
    }
};