class Solution {
public:
    int percentageLetter(string s, char letter) {
        int count=0;
        for(int i=0;i<s.size();++i){
            if(s[i]==letter){
                count++;
            }
        }
        int percentage=(count*100)/s.size();
        return percentage;
    }
};