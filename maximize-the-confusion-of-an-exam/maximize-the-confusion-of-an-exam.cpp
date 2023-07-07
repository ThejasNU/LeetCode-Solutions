class Solution {
public:
    int maxConsecutiveAnswers(string answerKey, int k) {
        int n=answerKey.size();
        int ans=k;
        int i=0;
        unordered_map<char,int> counter;
        
        while(i<n && i<k) counter[answerKey[i++]]+=1;

        int left=0;
        for(int right=k;right<n;++right){
            counter[answerKey[right]]+=1;
            while(min(counter['T'],counter['F'])>k) counter[answerKey[left++]]-=1;
            ans=max(ans,right-left+1);
        }
        return ans;
    }
};