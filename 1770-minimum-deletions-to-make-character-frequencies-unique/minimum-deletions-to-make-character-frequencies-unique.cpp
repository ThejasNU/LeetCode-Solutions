class Solution {
public:
    int minDeletions(string s) {
        unordered_map<char,int> counter;
        for(char c:s){
            counter[c]+=1;
        }

        int ans=0;
        unordered_set<int> seenFreqs;
        for(auto it:counter){
            int freq=it.second;
            while(freq>0 && seenFreqs.find(freq)!=seenFreqs.end()){
                freq-=1;
                ans+=1;
            }
            seenFreqs.insert(freq);
        }
        return ans;
    }
};