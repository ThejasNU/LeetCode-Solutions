class Solution {
public:
    bool checkRecord(string s) {
        int abCnt=0;
        int consLateCnt=0;
        for(int i=0;i<s.length();++i){
            if(s[i]=='A'){
                abCnt++;
            }
            else if(s[i]=='L'){
                if(s[i+1]=='L' && s[i+2]=='L'){
                    consLateCnt++;
                }
            }
        }
        if(abCnt>=2 || consLateCnt>0){
            return false;
        }else{
            return true;
        }
    }
};