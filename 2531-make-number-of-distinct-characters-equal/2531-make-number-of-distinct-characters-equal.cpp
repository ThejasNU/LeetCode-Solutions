class Solution {
public:
    bool isItPossible(string word1, string word2) {
        unordered_map<char, int> m1, m2;
        for(char ch: word1) m1[ch]++;
        for(char ch: word2) m2[ch]++;

        for(char ch1='a'; ch1 <= 'z'; ++ch1){
            for(char ch2='a'; ch2 <= 'z'; ++ch2){
                if(m1.count(ch1) && m2.count(ch2)){
                    if(--m1[ch1] == 0) m1.erase(ch1);
                    if(--m2[ch2] == 0) m2.erase(ch2);

                    m1[ch2]++;
                    m2[ch1]++;

                    if(m1.size() == m2.size())
                        return true;

                    if(--m1[ch2] == 0) m1.erase(ch2);
                    if(--m2[ch1] == 0) m2.erase(ch1);
                    m1[ch1]++;
                    m2[ch2]++;
                }
            }
        }
        return false;
    }
};