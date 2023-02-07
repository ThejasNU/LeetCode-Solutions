//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
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