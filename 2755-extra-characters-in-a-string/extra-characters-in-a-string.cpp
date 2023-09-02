class Solution {
public:
    int minExtraChar(string s, vector<string>& dictionary) {
        vector<int> dp(s.size(),-1);
        
        unordered_set<string> dict;
        for(string& word:dictionary){
            dict.insert(word);
        }

        return helper(0,s,dict,dp);
    }

    int helper(int idx,const string& s,unordered_set<string>& dict,vector<int>& dp){
        if(idx==s.size()) return 0;
        if(dp[idx]!=-1) return dp[idx];

        //skip
        int res=1+helper(idx+1,s,dict,dp);
        //find words
        for(int end=idx;end<s.size();++end){
            string curWord=s.substr(idx,end-idx+1);
            if(dict.find(curWord)!=dict.end()){
                res=min(res,helper(end+1,s,dict,dp));
            }
        }

        return dp[idx]=res;
    }
};