class Solution {
public:
    int minFlips(int a, int b, int c) {
        int ans=0;
        while(a!=0 || b!=0 || c!=0){
            if((c&1)==1){
                if((a&1)==0 && (b&1)==0) ans+=1;
            }
            else{
                ans+= (a&1) + (b&1);
            }
            a>>=1;
            b>>=1;
            c>>=1;
        }
        return ans;
    }
};

class noobSolution {
public:
    int minFlips(int a, int b, int c) {
        int bitA,bitB,bitC;
        int ans=0;
        for(int i=0;i<32;++i){
            bitA=(a>>i)&1;
            bitB=(b>>i)&1;
            bitC=(c>>i)&1;
            if((bitA==0 && bitB==0 && bitC!=0) || (bitA==0 && bitB==1 && bitC!=1) || (bitA==1 && bitB==0 && bitC!=1) || (bitA==1 && bitB==1 && bitC!=1)){
                if(bitC==0){
                    if((bitA==0 && bitB==1) || (bitA==1 && bitB==0)) ans+=1;
                    else ans+=2; 
                }
                else{
                    ans+=1;
                }
            }
        }
        return ans;
    }
};