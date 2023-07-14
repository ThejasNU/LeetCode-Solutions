//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
	public:
	int maxSumIS(int arr[], int n){  
	    int dp[n];
	    int ans=0;
	    for(int i=n-1;i>=0;--i){
	        dp[i]=arr[i];
	        for(int j=i+1;j<n;++j){
	            if(arr[j]>arr[i]) dp[i]=max(dp[i],arr[i]+dp[j]);
	        }
	        ans=max(ans,dp[i]);
	    }
	    return ans;
	}  
};

//{ Driver Code Starts.
int main() 
{
   	
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        int a[n];

        for(int i = 0; i < n; i++)
        	cin >> a[i];

      

	    Solution ob;
	    cout << ob.maxSumIS(a, n) << "\n";
	     
    }
    return 0;
}


// } Driver Code Ends