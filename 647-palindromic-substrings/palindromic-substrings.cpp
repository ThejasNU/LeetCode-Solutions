class Solution {
public:
    int countSubstrings(string s) {
        int n=s.size();
        int ans=0;

        for(int idx=0;idx<n;++idx){
            int i=idx;
            int j=idx;
            while(i>=0 && j<n && s[i]==s[j]){
                ans+=1;
                i-=1;
                j+=1;
            }

            i=idx;
            j=idx+1;
            while(i>=0 && j<n && s[i]==s[j]){
                ans+=1;
                i-=1;
                j+=1;
            }
        }
        return ans;
    }
};