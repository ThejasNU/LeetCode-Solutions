class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> s(wordList.begin(),wordList.end());
        
        int n=beginWord.size();
        
        queue<pair<string,int>>q;
        q.push({beginWord,1});
        s.erase(beginWord);
        string temp;
        while(!q.empty()){
            auto it=q.front();
            string cur=it.first;
            int steps=it.second;
            q.pop();
            
            if(cur==endWord) return steps;
            
            for(int i=0;i<n;++i){
                char original=cur[i];
                
                for(char ch='a';ch<='z';++ch){
                    cur[i]=ch;
                    if(s.find(cur)!=s.end()){
                        s.erase(cur);
                        q.push({cur,steps+1});
                    }
                }
                cur[i]=original;
            }
        }
        
        return 0;
    }
};