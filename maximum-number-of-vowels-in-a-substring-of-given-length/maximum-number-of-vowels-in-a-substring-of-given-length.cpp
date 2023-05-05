class Solution {
public:
    int maxVowels(string s, int k) {
        int i=0;
        int ans;
        int temp=0;
        while(i<k){
            if(s[i]=='a' || s[i]=='e' || s[i]=='i' || s[i]=='o' || s[i]=='u'){
                ++temp;
            }
            ++i;
        }
        ans=temp;
        while(i<s.size()){
            if(s[i-k]=='a' || s[i-k]=='e' || s[i-k]=='i' || s[i-k]=='o' || s[i-k]=='u'){
                --temp;
            }
            if(s[i]=='a' || s[i]=='e' || s[i]=='i' || s[i]=='o' || s[i]=='u'){
                ++temp;
            }
            ans=max(ans,temp);
            ++i;
        }
        return ans;
    }
};