//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    vector<int> dp;
    int minimumEnergy(vector<int>& height, int n) {
        dp.resize(n,-1);
        helper(n-1,height);
        return dp[n-1];
    }
    
    int helper(int ind,vector<int> &height){
        if(ind==0) return 0;
        if(dp[ind]!=-1) return dp[ind];
        
        int ans=INT_MAX;
        
        if(ind-1>=0) ans=min(ans,helper(ind-1,height)+abs(height[ind]-height[ind-1]));
        if(ind-2>=0) ans=min(ans,helper(ind-2,height)+abs(height[ind]-height[ind-2]));
        
        return dp[ind]=ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        vector<int> arr(N);
        for (int i = 0; i < N; i++) {
            cin >> arr[i];
        }
        Solution obj;
        cout << obj.minimumEnergy(arr, N) << "\n";
    }
    return 0;
}
// } Driver Code Ends