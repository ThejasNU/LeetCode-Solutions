class Solution {
public:
    vector<string> uncommonFromSentences(string s1, string s2) {
        stringstream ss1(s1);
        stringstream ss2(s2);

        map<string,int> m;
        string word;
        while(ss1>>word){
            m[word]++;
        }
        while(ss2>>word){
            m[word]++;
        }

        vector<string> ans;
        for(auto& [word,count]:m){
            if(count==1){
                ans.push_back(word);
            }
        }
        
        return ans;
    }
};