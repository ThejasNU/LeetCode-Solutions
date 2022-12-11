class Solution {
public:
    int maximumValue(vector<string>& strs) {
        bool isAlpha=false;
        bool isNumeric=false;
        
        int ans=INT_MIN;
        
        for(int i=0;i<strs.size();++i){
            isAlpha=false;
            isNumeric=false;
            
            for(char c:strs[i]){
                if(!isNumeric && c-'0'<10 && c-'0'>=0) isNumeric=true;
                else if(!isAlpha && (c-'0'>=10 || c-'0'<0)) isAlpha=true;
            }
            
            if(isAlpha && !isNumeric){
                ans=max(ans,(int)strs[i].size());
            }
            else if(!isAlpha && isNumeric){
                ans=max(ans,stoi(strs[i]));
            }
            else{
                ans=max(ans,(int)strs[i].size());
            }
        }
        
        return ans;
    }
};