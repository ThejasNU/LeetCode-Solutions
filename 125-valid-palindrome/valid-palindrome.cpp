class Solution {
public:
    bool isPalindrome(string s) {
        int l=0;
        int r=s.size()-1;
        while(l<r){
            if(!(s[l]>='a' && s[l]<='z') && !(s[l]>='A' && s[l]<='Z') && !(s[l]>='0' && s[l]<='9')){
                ++l;
            }
            else if(!(s[r]>='a' && s[r]<='z') && !(s[r]>='A' && s[r]<='Z') && !(s[r]>='0' && s[r]<='9')){
                --r;
            }
            else if(s[l]==s[r] || toupper(s[l])==s[r] || s[l]==toupper(s[r])){
                ++l;
                --r;
            }
            else{
                return false;
            }
        }
        return true;
    }
};