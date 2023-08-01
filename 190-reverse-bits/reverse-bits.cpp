class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t ans=0;
        for(int i=0;i<32;++i){
            ans<<=1;
            ans|=(n&1);
            n>>=1;
        }
        return ans;
    }
};

class altSolution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t ans=0;
        for(int i=0;i<32;++i){
            if(((n>>i)&1)==1){
                ans|=(1<<(31-i));
            }
        }
        return ans;
    }
};