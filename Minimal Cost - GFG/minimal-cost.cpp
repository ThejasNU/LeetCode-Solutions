//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    
    int minimizeCost(vector<int>& height, int n, int k) {
        vector<int> dp(n,INT_MAX);
        dp[n-1]=0;
        for(int i=n-2;i>=0;--i){
            for(int j=1;j<=k;++j){
                if(i+j<n) dp[i]=min(dp[i],dp[i+j]+abs(height[i]-height[i+j]));   
            }
        }
        return dp[0];
    }
};


class topDownSolution {
  public:
    vector<int> dp;
    int minimizeCost(vector<int>& height, int n, int k) {
        dp.resize(n,-1);
        helper(0,height,n,k);
        return dp[0];
    }
    
    int helper(int ind,vector<int>& height,int n,int k){
        if(ind==n-1) return 0;
        if(dp[ind]!=-1) return dp[ind];
        
        int ans=INT_MAX;
        for(int i=1;i<=k;++i){
            if(ind+i<n) ans=min(ans,abs(height[ind]-height[ind+i])+helper(ind+i,height,n,k));
        }
        return dp[ind]=ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, K;
        cin >> N >> K;
        vector<int> arr(N);
        for (int i = 0; i < N; i++) {
            cin >> arr[i];
        }
        Solution obj;
        cout << obj.minimizeCost(arr, N, K) << "\n";
    }
    return 0;
}
// } Driver Code Ends