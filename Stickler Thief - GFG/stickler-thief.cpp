//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

// } Driver Code Ends
class Solution
{
    public:
    int FindMaxSum(int arr[], int n){
        int prev=arr[0];
        int prev2=0;
        
        for(int i=1;i<n;++i){
            int notTake=prev;
            int take=arr[i]+prev2;
            int cur=max(take,notTake);
            prev2=prev;
            prev=cur;
        }
        return prev;
    }
};

class tabulationSolution{
public:
	int FindMaxSum(int *arr, int n) {
	    vector<int> dp(n);
        dp[0]=arr[0];
        
        for(int i=1;i<n;++i){
            int notTake=dp[i-1];
            int take=arr[i]+(i>1?dp[i-2]:0);
            dp[i]=max(take,notTake);
        }
        return dp[n-1];
	}
};

class topDownSolution{
public:
    vector<int> dp;
	int FindMaxSum(int *arr, int n) {
	   dp.resize(n,-1);
	   return helper(arr,n,0);
	}
	
	int helper(int *arr,int n,int ind){
	    if(ind>=n) return 0;
	    if(dp[ind]!=-1) return dp[ind];
	    
	    int ans=helper(arr,n,ind+1);
	    ans=max(ans,arr[ind]+helper(arr,n,ind+2));
	    return dp[ind]=ans;
	}
};


//{ Driver Code Starts.
int main()
{
    //taking total testcases
	int t;
	cin>>t;
	while(t--)
	{
	    //taking number of houses
		int n;
		cin>>n;
		int a[n];
		
		//inserting money of each house in the array
		for(int i=0;i<n;++i)
			cin>>a[i];
		Solution ob;
		//calling function FindMaxSum()
		cout<<ob.FindMaxSum(a,n)<<endl;
	}
	return 0;
}

// } Driver Code Ends