class Solution {
public:
    int characterReplacement(string s, int k) {
        int n=s.size();
        vector<int> count(26,0);
        int i=0,j=0;
        int maxCount=0;
        int ans=0;
        while(j<n){
            int idx=s[j]-'A';
            count[idx]+=1;
            maxCount=max(maxCount,count[idx]);

            if((j-i+1-maxCount)>k){
                count[s[i]-'A']-=1;
                i+=1;
            }
            ans=max(ans,j-i+1);
            j+=1;
        }
        return ans;
    }
};