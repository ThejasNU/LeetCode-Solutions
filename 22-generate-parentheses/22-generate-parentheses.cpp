class Solution {
public:
    vector<string> ans;
    
    void generate(string &s,int open,int close){
        if(open==0 && close==0){
            ans.push_back(s);
            return;
        }
        
        if(open>0){
            s.push_back('(');
            generate(s,open-1,close);
            s.pop_back(); //this is done so that it will nto affect the branching at last node in backtracking tree
        }
        
        if(close>0){
            if(open<close){
                s.push_back(')');
                generate(s,open,close-1);
                s.pop_back();
            }
            
        }
    }
    vector<string> generateParenthesis(int n) {
        string s;
        generate(s,n,n);
        
        return ans;
    }
};