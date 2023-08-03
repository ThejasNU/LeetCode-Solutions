class Solution {
public:
    vector<string> letterCombinations(string digits) {
        int n=digits.size();
        unordered_map<char,string> m;
        m.insert({'2',"abc"});
        m.insert({'3',"def"});
        m.insert({'4',"ghi"});
        m.insert({'5',"jkl"});
        m.insert({'6',"mno"});
        m.insert({'7',"pqrs"});
        m.insert({'8',"tuv"});
        m.insert({'9',"wxyz"});
        vector<string> ans;
        string temp;

        function<void(int)> helper=[&](int idx){
            if(idx==n){
                if(temp!="") ans.push_back(temp);
                return;
            }

            for(char c:m[digits[idx]]){
                temp.push_back(c);
                helper(idx+1);
                temp.pop_back();
            }
        };
        
        helper(0);
        return ans;
    }
};