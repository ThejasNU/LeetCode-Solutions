class anotherSolution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        int i=0,j=0;
        int n=pushed.size();
        stack<int> st;
        while(i<n && j<n){
            while(i<n){
                st.push(pushed[i]);
                ++i;
                if(st.top()==popped[j]) break;
            }
            while(j<n && !st.empty() && st.top()==popped[j]){
                st.pop();
                ++j;
            }
        }
        return i==n && j==n ;
    }
};

class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        int i=0,j=0;
        int n=pushed.size();
        stack<int> st;
        while(i<n){
            st.push(pushed[i]);
            while(!st.empty() && j<n && st.top()==popped[j]){
                st.pop();
                ++j;
            }
            ++i;
        }
        return j==n;
    }
};