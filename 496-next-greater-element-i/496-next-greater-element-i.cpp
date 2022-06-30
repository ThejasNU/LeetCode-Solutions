class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        
        stack<int> st;
        unordered_map<int,int> m;
        
        for(int i=0;i<nums2.size();++i){
            if(!st.empty() && nums2[i]>nums2[st.top()]){
                while(!st.empty() && nums2[i]>nums2[st.top()]){
                    m[nums2[st.top()]]=nums2[i];
                    st.pop();
                }
            }
            st.push(i);
        }
        
        vector<int> res(nums1.size(),-1); //array initialised with -1
        
        for(int j=0;j<nums1.size();++j){
            if(m.find(nums1[j])!=m.end()){
                res[j]=m[nums1[j]];
            }
        }
        
        return res;
    }
};