class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n=s.size();
        unordered_map<char,int> lastIdx;
        int maxLen=0;
        int l=0,r=0;
        while(r<n){
            if(lastIdx.find(s[r])!=lastIdx.end()){
                //if we have already crossed the last occurance of a character, we don't need to go back again
                l=max(l,lastIdx[s[r]]+1);
            }
            lastIdx[s[r]]=r;
            maxLen=max(maxLen,r-l+1);
            ++r;
        }
        return maxLen;
    }
};

class noobSolution {
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