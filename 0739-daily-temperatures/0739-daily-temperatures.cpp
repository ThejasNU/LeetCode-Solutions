class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector<int> ans(temperatures.size(),0);
        stack<int> st;
        
        for(int i=0;i<temperatures.size();++i){
            if(st.empty()) st.push(i);
            else{
                while(!st.empty() && temperatures[st.top()]<temperatures[i]){
                    ans[st.top()]=i-st.top();
                    st.pop();
                }
                st.push(i);
            }
        }
        
        return ans;
    }
};