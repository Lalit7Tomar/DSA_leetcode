class Solution {
public:
    bool rightrotate(string s,string goal,int k){
          // reverse n-k
          string f=s;
          int n=s.length();
          for(int i=0;i<(n-k)/2;i++){
            swap(f[i],f[n-i-k-1]);
          }
          for(int i=n-k;i<(2*n-k)/2;i++){
            swap(f[i],f[2*n-1-i-k]);
          }
          for(int i=0;i<n/2;i++){
            swap(f[i],f[n-1-i]);
          }
          if(f==goal){
            return true;
          }
          return false;
    }
    bool rotateString(string s, string goal) {
        int n=s.length();
        for(int i=0;i<n;i++){
            bool result=rightrotate(s,goal,i);
              if(result==true){
                return true;
              }
        }
       return false;
    }
};