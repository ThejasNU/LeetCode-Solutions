class Solution {
public:
    string longestPalindrome(string s) {
        int n=s.size();
        int bigStrStart=0;
        int maxLen=0;
        int l,r,curLen;
        for(int i=0;i<n;++i){
            //odd length str
            l=i,r=i;
            while(l>=0 && r<n && s[l]==s[r]){
                --l;
                ++r;
            }
            //--l; ++r;
            //curLen=r-l+1;
            //or
            // curLen=(r-1)-(l+1)+1;
            curLen=r-1-l;
            if(curLen > maxLen){
                bigStrStart=l+1;
                maxLen=curLen;
            }

            //even length str
            l=i;
            r=i+1;
            while(l>=0 && r<n && s[l]==s[r]){
                --l;
                ++r;
            }
            curLen=r-1-l;
            if(curLen > maxLen){
                bigStrStart=l+1;
                maxLen=curLen;
            }
        }
        return s.substr(bigStrStart,maxLen);
    }
};