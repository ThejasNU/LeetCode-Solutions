class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<long long> st;
        
        long long a,b;
        for(string token:tokens){
            if(token=="+"){
                a=st.top();
                st.pop();
                b=st.top();
                st.pop();
                
                st.push(a+b);
            }
            else if(token=="-"){
                a=st.top();
                st.pop();
                b=st.top();
                st.pop();
                
                st.push(b-a);
            }
            else if(token=="*"){
                a=st.top();
                st.pop();
                b=st.top();
                st.pop();
                
                st.push(a*b);
            }
            else if(token=="/"){
                a=st.top();
                st.pop();
                b=st.top();
                st.pop();
                
                st.push(b/a);
            }
            else{
                st.push(stoll(token));
            }
        }
        
        return st.top();
    }
};