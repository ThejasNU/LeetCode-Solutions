class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> cur;
        
        solve(s,0,cur,ans);
        return ans;
    }
    
    void solve(string &s,int start,vector<string> &cur,vector<vector<string>> &ans){
        if(start>=s.size()){
            ans.push_back(cur);
            return;
        }
        
        for(int end=start;end<s.size();++end){
            if(isPalindrome(s,start,end)){
                cur.push_back(s.substr(start,end-start+1));
                solve(s,end+1,cur,ans);
                cur.pop_back();
            }
        }
    }
    
    bool isPalindrome(string &s,int low,int high){
        while(low<high){
            if(s[low++]!=s[high--]) return false;
        }
        
        return true;
    }
};