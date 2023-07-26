class Solution {
public:
    //LOGIC: num*2==num<<1 so the number of bits in ith index==i/2th index
    vector<int> countBits(int n) {
        vector<int> ans(n+1);
        ans[0]=0;
        for(int i=1;i<=n;++i){
            if(i%2==0) ans[i]=ans[i/2];
            else ans[i]=ans[i-1]+1;
        }
        return ans;
    }
};