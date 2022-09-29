class Solution {
public:
    int longestContinuousSubstring(string s) {
        if(s=="") return 0;
        int cur=1;
        int maxi=1;
        for(int i=1;i<s.size();++i){
            if(s[i]-'a'==(s[i-1]-'a')+1){
                cur++;
                maxi=max(cur,maxi);
            }
            else{
                cur=1;
            }
        }
        return maxi;
    }
};