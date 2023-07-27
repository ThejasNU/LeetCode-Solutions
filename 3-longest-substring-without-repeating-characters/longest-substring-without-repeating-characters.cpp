class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n=s.size();
        unordered_map<char,int> counter;
        int maxLen=0;
        int curLen=0;
        for(int i=0;i<n;++i){
            counter[s[i]]+=1;

            int idx=i-curLen;
            while(counter[s[i]]!=1){
                counter[s[idx]]-=1;
                idx+=1;
                curLen-=1;
            }

            //add current char to the size
            curLen+=1;
            maxLen=max(maxLen,curLen);
        }
        return maxLen;
    }
};