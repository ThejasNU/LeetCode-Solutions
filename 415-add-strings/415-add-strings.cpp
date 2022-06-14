class Solution {
public:
    string addStrings(string num1, string num2) {
        int len1=num1.size();
        int len2=num2.size();
        while(num1.size()!=num2.size()){
            if(num1.size()<num2.size()){
                num1="0"+num1;
            }else{
                num2="0"+num2;
            }
        }
        
        int carry=0;
        string res="";
        int digitSum;
        int digitToBePlaced;
        
        for(int i=num1.size()-1;i>=0;--i){
            digitSum=(num1[i]-'0')+(num2[i]-'0')+carry;
            carry=digitSum/10;
            digitToBePlaced=digitSum%10;
            res+=(digitToBePlaced+'0');
        }
        if(carry){
            res+=(carry+'0');
        }
        reverse(res.begin(),res.end());
        return res;
    }
};