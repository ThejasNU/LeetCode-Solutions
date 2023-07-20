class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> st;
        for(int ast:asteroids){
            if(!st.empty()){
                bool flag=true;
                if(ast<0){
                    while(!st.empty() && st.top()>0){
                        if(abs(ast)>st.top()){
                            st.pop();
                            continue;
                        }
                        else if(abs(ast)==st.top()){
                            st.pop();
                        }
                        flag=false;
                        break;
                    }
                }
                if(flag) st.push(ast);
            }
            else{
                st.push(ast);
            }
        }
        vector<int> ans(st.size());
        int n=st.size()-1;
        while(!st.empty()){
            ans[n]=st.top();
            st.pop();
            --n;
        }
        return ans;
    }
};