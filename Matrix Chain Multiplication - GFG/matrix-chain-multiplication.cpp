//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int dp[101][101];
    int matrixMultiplication(int N, int arr[]){
        memset(dp,-1,sizeof(dp));
        return helper(1,N-1,arr);
    }
    
    int helper(int start,int end,int arr[]){
        if(start>=end) return 0;
        if(dp[start][end]!=-1) return dp[start][end];
        int ans=INT_MAX;
        for(int idx=start;idx<=end-1;++idx){
            ans=min(ans,helper(start,idx,arr)+helper(idx+1,end,arr)+arr[start-1]*arr[idx]*arr[end]);
        }
        return dp[start][end]=ans;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int arr[N];
        for(int i = 0;i < N;i++)
            cin>>arr[i];
        
        Solution ob;
        cout<<ob.matrixMultiplication(N, arr)<<endl;
    }
    return 0;
}
// } Driver Code Ends