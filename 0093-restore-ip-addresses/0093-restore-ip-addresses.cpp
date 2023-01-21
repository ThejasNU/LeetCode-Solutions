class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        vector<int> dots;
        vector<string> ans;
        helper(s,0,dots,ans);
        return ans;
    }
    
    void helper(string &s,int start,vector<int> &dots,vector<string> &ans){
        int remainingLength=s.size()-start;
        int remainingNums=4-dots.size();
        
        if(remainingLength>remainingNums*3 || remainingLength<remainingNums) return;
        
        if(dots.size()==3){
            if(isValid(s,start,remainingLength)){
                string temp;
                int last=0;
                for(int dot:dots){
                    temp.append(s.substr(last,dot));
                    last+=dot;
                    temp.push_back('.');
                }
                temp.append(s.substr(start));
                ans.push_back(temp);
            }
            
            return;
        }
        
        for(int curPos=1;curPos<=3 && curPos<=remainingLength;++curPos){
            dots.push_back(curPos);
            if(isValid(s,start,curPos)) helper(s,start+curPos,dots,ans);
            dots.pop_back();
        }
    }
    
    bool isValid(string &s,int start,int len){
        return len==1 || (s[start]!='0' && (len<3 || s.substr(start,len)<="255"));
    }
};