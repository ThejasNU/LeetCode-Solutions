class Solution {
public:
    double myPow(double x, int n) {
        double ans=1.0;
        long long power=n;
        if(power<0) power*=-1LL;

        while(power>0){
            if(power%2==0){
                x*=x;
                power/=2;
            }
            else{
                ans=ans*x;
                power-=1;
            }
        }
        
        if(n<0) ans=1/ans;
        return ans;
    }
};