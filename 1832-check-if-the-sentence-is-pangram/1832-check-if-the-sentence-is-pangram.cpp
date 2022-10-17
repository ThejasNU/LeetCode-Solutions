class Solution {
public:
    bool checkIfPangram(string sentence) {
        unordered_map<int,int> m;
        
        for(char alphabet:sentence){
            m[alphabet-'a']++;
        }
        
        return m.size()==26?true:false;
    }
};