class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        int M=1e9+7;
        int n=arr.size();
        vector<int> dp(n,0);
        stack<int> st;
        
        for(int i=0;i<n;++i){
            while(!st.empty() && arr[st.top()]>=arr[i]){
                st.pop();
            }
            
            if(!st.empty()){
                int prevSmall=st.top();
                dp[i]=dp[prevSmall]+(i-prevSmall)*arr[i];
            }
            else{
                dp[i]=(i+1)*arr[i];
            }
            
            st.push(i);
        }
        
        long ans=0;
        
        for(int num:dp){
            ans+= num;
            ans%=M;
        }
        
        return (int)ans;
    }
};