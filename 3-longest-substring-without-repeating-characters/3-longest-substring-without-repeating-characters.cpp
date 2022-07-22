class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char,int> m;
        
        int left=0,right=0;
        int n=s.size();
        int len=0;
        
        while(right<n){
            if(m.find(s[right])!=m.end()){
                left=max(m[s[right]]+1,left);
            }
            m[s[right]]=right;
            len=max(len,right-left+1);
            right++;
        }
        return len;
    }
};