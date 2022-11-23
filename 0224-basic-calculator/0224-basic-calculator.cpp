class Solution {
public:
    int calculate(string s) {
        int res = 0, n = s.size(), sign = 1, sign_cur = 1;
        stack<int> st;
        for(int i = 0; i < n; i++){
            if(s[i] == ' ') continue;
            else if(s[i] == '+') sign_cur = 1;
            else if(s[i] == '-') sign_cur = -1;
            else if(s[i] == '(') sign *= sign_cur, st.push(sign_cur), sign_cur = 1;
            else if(s[i] == ')') sign *= st.top(), st.pop(), sign_cur = 1;
            else res += sign*sign_cur*getN(i, s);
        }
        return res;
    }

    int getN(int& idx, string& s){
        int res = 0;
        while(idx<s.size() && s[idx]>='0' && s[idx]<='9')
            res = 10*res+(s[idx++]-'0');
        idx--;
        return res;
    }
};