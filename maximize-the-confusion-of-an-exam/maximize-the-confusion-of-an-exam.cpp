class Solution {
public:
    int maxConsecutiveAnswers(string answerKey, int k) {
        int n=answerKey.size();
        int maxSize=0;
        unordered_map<char,int> counter;
        
        for(int right=0;right<n;++right){
            counter[answerKey[right]]+=1;
            int minCount=min(counter['T'],counter['F']);
            if(minCount<=k){
                maxSize++;
            }
            else{
                counter[answerKey[right-maxSize]]-=1;
            }
        }
        return maxSize;
    }
};

class altSolution {
public:
    int maxConsecutiveAnswers(string answerKey, int k) {
        int n=answerKey.size();
        int ans=k;
        unordered_map<char,int> counter;
        
        int i=0;
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