class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> st;
        for(int ast:asteroids){
            if(!st.empty()){
                if(ast<0){
                    bool flag=true;
                    while(!st.empty() && st.top()>0){
                        if(abs(ast)<st.top()){
                            flag=false;
                            break;
                        }
                        else if(abs(ast)==st.top()){
                            flag=false;
                            st.pop();
                            break;
                        }
                        else st.pop();
                    }
                    if(flag) st.push(ast);
                }
                else st.push(ast);
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