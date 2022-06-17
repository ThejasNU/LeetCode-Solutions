class Solution {
public:
    bool isPalindrome(int x) {
        if(x<0){
            return false;
        }
        
        long long int revNum=0;
        long long int lastDigit;
        long long int temp=x;
        
        while(temp!=0){
            lastDigit=temp%10;
            temp=temp/10;
            revNum=revNum*10+lastDigit;
        }
        
        if(revNum==x)return true;
        else return false;
        
    }
};