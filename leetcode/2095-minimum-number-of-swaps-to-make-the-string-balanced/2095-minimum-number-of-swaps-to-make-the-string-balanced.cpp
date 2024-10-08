class Solution {
public:
    int minSwaps(string s) {
        // count [ which appear after ]
        int extraCnt=0;
        for(char c:s){
            if(c=='['){
                ++extraCnt;
            } else {
                if(extraCnt>0){
                    --extraCnt;
                }
            }
        }
        return (extraCnt+1)/2;
    }
};