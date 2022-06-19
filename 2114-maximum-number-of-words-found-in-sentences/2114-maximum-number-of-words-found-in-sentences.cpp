class Solution {
public:
    int mostWordsFound(vector<string>& sentences) {
        int max=0;
        int eleSum;
        
        for(int i=0;i<sentences.size();++i){
            eleSum=0;
            for(int j=0;j<sentences[i].size();++j){
                if(sentences[i][j]==' ') eleSum++;
            }
            if(eleSum+1>max) max=eleSum+1; //Number of words==Number of spaces+1
        }
        
        return max;
        
    }
};