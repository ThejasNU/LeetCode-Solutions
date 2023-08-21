class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        int len=s.size();

        for(int i=1;i<=len/2;++i){
            if(len%i!=0) continue;

            string pattern=s.substr(0,i);
            string temp="";
            for(int j=0;j<len/i;++j){
                temp+=pattern;
            }
            if(temp==s) return true;
        }

        return false;
    }
};