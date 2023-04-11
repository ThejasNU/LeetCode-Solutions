class Solution {
public:
    string removeStars(string s) {
        int start=0,main=0,i=0;
        int n=s.size();
        
        while(i<n){
            while(i<n && s[i]!='*') ++i;
            int starsCount=0;
            while(i<n && s[i]=='*'){
                ++starsCount;
                ++i;
            }
            int numChars=i-start-starsCount;
            int charsToAdd=numChars-starsCount;
            if(numChars<starsCount){
                int dif=starsCount-numChars;
                main-=dif;
            }
            while(charsToAdd>0){
                s[main]=s[start];
                ++main;
                ++start;
                --charsToAdd;
            }
            start=i;
        }
        return s.substr(0,main);
    }
};