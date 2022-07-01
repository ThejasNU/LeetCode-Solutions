class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n=nums.size();
        
        stack<int> st;
        vector<int> res(n,-1);
        
        //need to iterate two times through the array
        for(int i=0;i<2*n;++i){
            if(!st.empty() && nums[st.top()]<nums[i%n]){
                while(!st.empty() && nums[st.top()]<nums[i%n]){
                    res[st.top()]=nums[i%n];
                    st.pop();
                }
            }
            st.push(i%n);
        }
    
        return res;
    }
};