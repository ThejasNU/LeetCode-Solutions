class Solution {
public:
    //hare and tortoise algo to find cycles
    bool isHappy(int n) {
        int slow=n;
        int fast=getNext(n);
        while(fast!=1 && slow!=fast){
            slow=getNext(slow);
            fast=getNext(getNext(fast));
        }
        return fast==1;
    }
    
    int getNext(int n){
        int sum=0;
        while(n>0){
            int d=n%10;
            n/=10;
            sum+=pow(d,2);
        }
        return sum;
    }
};