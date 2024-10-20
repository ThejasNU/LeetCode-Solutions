class Solution {
public:
    bool parseBoolExpr(string expression) {
        stack<char> st;

        for (char c : expression) {
            if (c == ',' || c == '(') {
                continue;
            }

            if (c == ')') {
                bool hasTrue = false, hasFalse = false;

                while (st.top() != '!' && st.top() != '|' && st.top() != '&') {
                    char temp = st.top();
                    st.pop();

                    if (temp == 'f' && !hasFalse) {
                        hasFalse = true;
                    } else if (temp == 't' && !hasTrue) {
                        hasTrue = true;
                    }
                }

                char op = st.top();
                st.pop();

                switch (op) {
                case '!':
                    st.push(hasTrue ? 'f' : 't');
                    break;
                case '|':
                    st.push(hasTrue ? 't' : 'f');
                    break;
                case '&':
                    st.push(hasFalse ? 'f' : 't');
                    break;
                }
            } else {
                st.push(c);
            }
        }

        return st.top() == 't';
    }
};