class Solution {
public:
    bool areSentencesSimilar(string sentence1, string sentence2) {
        stringstream ss1(sentence1),ss2(sentence2);
        vector<string> words1,words2;

        string word;
        while(ss1>>word){
            words1.push_back(word);
        }
        while(ss2>>word){
            words2.push_back(word);
        }

        int l=0, r1 = words1.size()-1, r2 = words2.size()-1;

        if(r1>r2){
            swap(r1,r2);
            swap(words1,words2);
        }

        while(l<words1.size() && words1[l]==words2[l]){
            ++l;
        }
        while(r1>=0 && words1[r1]==words2[r2]){
            --r1;
            --r2;
        }

        return r1<l;
    }
};