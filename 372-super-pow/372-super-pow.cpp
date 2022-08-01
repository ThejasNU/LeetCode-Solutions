class Solution {
public:
    //ETM technique
    
    int M=1337;
    //1337*(1-1/7)*(1-1/191)
    int phi_M=1140;
    
    int superPow(int a, vector<int>& b) {
        
        int power=0;
        
        for(int i=0;i<b.size();++i){
            power=(power*10+b[i])%phi_M;
        }
        
        a%=M;
        int res=1;
        while(power){
            if(power&1){
                res=(res*a)%M;
            }
            a=(a*a)%M;
            power>>=1;
        }
        
        return res;
    }
};