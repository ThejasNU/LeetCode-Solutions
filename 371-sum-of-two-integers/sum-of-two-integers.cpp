class Solution {
public:
    int getSum(int a, int b) {
        while(b!=0){
            //get carry
            unsigned int carry=(a&b);
            //calculate the sum of remaining bits
            a=a^b;
            //make b the carry
            b=(carry<<1);
        }
        return a;
    }
};