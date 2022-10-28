class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,vector<string>> m;
        
        for(string s:strs){
            string temp=s;
            sort(temp.begin(),temp.end());
            m[temp].push_back(s);
        }
        
        vector<vector<string>> anagrams;
        
        for(auto it:m){
            anagrams.push_back(it.second);
        }
        
        return anagrams;
    }
};