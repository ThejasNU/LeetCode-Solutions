class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> curWords,ans;
        int curLen=0;

        for(string& word:words){
            //prev lengths+word size+spaces
            if(curLen+word.size()+curWords.size()>maxWidth){
                pushLine(curWords,ans,curLen,maxWidth);
            }
            
            curWords.push_back(word);
            curLen+=word.size();
        }

        //last line
        if(!curWords.empty()){
            string lastLine="";
            for(string& curWord:curWords){
                if(!lastLine.empty()){
                    lastLine.append(" ");
                }

                lastLine.append(curWord);
            }

            lastLine.append(string(maxWidth-lastLine.size(),' '));
            ans.push_back(lastLine);
        }
        
        return ans;
    }

    void pushLine(vector<string>& curWords,vector<string>& ans,int& curLen,int maxWidth){
        int totalSpaces=maxWidth-curLen;
        int gaps=curWords.size()-1;
        if(gaps==0){
            ans.push_back(curWords[0]+string(totalSpaces,' '));
        }
        else{
            int spacePerGap=totalSpaces/gaps;
            int extraSpaces=totalSpaces%gaps;
            string line="";
            for(string& curWord:curWords){
                line.append(curWord);
                if(gaps>0){
                    line.append(string(spacePerGap,' '));
                    gaps-=1;
                    if(extraSpaces>0){
                        line.append(" ");
                        extraSpaces-=1;
                    }
                }
            }
            ans.push_back(line);
        }
        curWords.clear();
        curLen=0;
    }
};