class Solution {
public:
    int addDigits(int num) {
        int ans=0;
        while(num>0){
            ans+=num%10;
            num/=10;
            if(num==0 && ans>9){
                num=ans;
                ans=0;
            }
        }
        return ans;
    }
};

class anotherSolution {
public:
    int addDigits(int num) {
        string ans=to_string(num);
        while(ans.size()>1){
            int temp=0;
            for(char c:ans){
                temp+=c-'0';
            }
            ans=to_string(temp);
        }
        return stoi(ans);
    }
};