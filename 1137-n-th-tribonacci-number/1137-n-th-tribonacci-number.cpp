class Solution {
public:
    int tribonacci(int n) {
        if(n==0) return 0;
        else if(n==1) return 1;
        else if(n==2) return 1;
        else{
            int n1=0,n2=1,n3=1;
            for(int i=3;i<=n;++i){
                int temp=n3+n2+n1;
                n1=n2;
                n2=n3;
                n3=temp;
            }
            return n3;
        }
    }
};