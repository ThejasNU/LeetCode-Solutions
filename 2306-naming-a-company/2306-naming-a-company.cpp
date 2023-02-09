class Solution {
public:
    long long distinctNames(vector<string>& ideas) {
        unordered_set<string> initialGroup[26];
        for(auto idea:ideas) initialGroup[idea[0]-'a'].insert(idea.substr(1));
        
        long long ans=0;
        for(int i=0;i<25;++i){
            for(int j=i+1;j<26;++j){
                int commonWords=0;
                for(auto ideaA:initialGroup[i]){
                    if(initialGroup[j].count(ideaA)) commonWords++;
                }
                ans+=2LL*(initialGroup[i].size()-commonWords)*(initialGroup[j].size()-commonWords);
            }
        }
        return ans;
    }
};