class Solution {
public:
    string convertToTitle(int columnNumber) {
        string ans="";
        while(columnNumber>0){
            columnNumber-=1;
            char c='A'+(columnNumber%26);
            ans.push_back(c);
            columnNumber/=26;
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};