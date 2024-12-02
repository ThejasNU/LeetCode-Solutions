class Solution {
public:
    int isPrefixOfWord(string sentence, string searchWord) {
        int searchLen=searchWord.size();
        
        stringstream ss(sentence);
        
        string word;
        int idx=0;
        while(ss >> word){
            ++idx;
            
            if(word.size()<searchLen){
                continue;
            }

            if(word.substr(0,searchLen)==searchWord){
                return idx;
            }
        }

        return -1;
    }
};