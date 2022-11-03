class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        unordered_map<string,int> m;
        
        for(auto word:words){
            m[word]++;
        }
        
        int ans=0;
        bool central=false;
        
        for(auto it:m){
            if(it.first[0]==it.first[1]){
                if(it.second%2==0) ans+=it.second;
                else{
                    ans+=it.second-1;
                    central=true;
                }
            }
            else if(it.first[0]<it.first[1] && m.count({it.first[1],it.first[0]})){
                ans+= 2*min(it.second,m[{it.first[1],it.first[0]}]);
            }
        }
        
        if(central){
            ans++;
        }
        
        return 2*ans;
    }
};