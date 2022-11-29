class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> ans;
        unordered_map<char,string> m;
        m['2']="abc";
        m['3']="def";
        m['4']="ghi";
        m['5']="jkl";
        m['6']="mno";
        m['7']="pqrs";
        m['8']="tuv";
        m['9']="wxyz";
        int n=digits.size();
        helper(digits,ans,m,"",n);
        return ans;
    }
    
    void helper(string digits,vector<string> &ans,unordered_map<char,string> &m,string temp,int n){
        if(digits=="") return;
        
        for(char c:m[digits[0]]){
            temp.push_back(c);
            if(temp.size()==n) ans.push_back(temp);
            else helper(digits.substr(1),ans,m,temp,n);
            temp.pop_back();
        }

    }
};