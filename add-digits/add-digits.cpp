class Solution {
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