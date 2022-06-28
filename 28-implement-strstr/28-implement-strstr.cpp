class Solution {
public:
    int strStr(string haystack, string needle) {
        int m=haystack.size();
        int n=needle.size();
        
        for(int i=0;i < m-n+1;++i){
            int k=0;
            while(haystack[i+k]==needle[k] && k<n){
                k++;
            }
            if(k==n) return i;
        }
        return -1;
    }
};