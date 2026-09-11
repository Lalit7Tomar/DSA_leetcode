class Solution {
public:
    const long long mod=1e9+7;
    long long an(long long n,long long base){
        long long ans=1;
        while(n>0){
            if(n%2==1){
             ans=(ans*base)%mod;
             n--;
            }
            base=(base*base)%mod;
            n=n/2;

        }
        return (ans)%mod;
    }
    int countGoodNumbers(long long n) {
       long long evenindexes=(n+1)/2;
       long long oddindexes=n/2;
       if(n==0) return 0;
       int num=1000000007;
       long long ans1=an(evenindexes,5);
        long long ans2=an(oddindexes,4);
       return (ans1*ans2)%mod;
    }
};