//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    int dp[1001][1001];
    int knapSack(int W, int wt[], int val[], int n) { 
       memset(dp,-1,sizeof(dp));
       return helper(0,W,wt,val,n);
    }
    
    int helper(int idx,int capacityLeft,int wt[],int val[],int n){
        if(idx==n || capacityLeft==0) return 0;
        if(dp[idx][capacityLeft]!=-1) return dp[idx][capacityLeft];
        
        //ignore the current bag
        int ans=helper(idx+1,capacityLeft,wt,val,n);
        
        //pickup the current bag
        if(capacityLeft-wt[idx]>=0)ans=max(ans,val[idx]+helper(idx+1,capacityLeft-wt[idx],wt,val,n));
        
        return dp[idx][capacityLeft]=ans;
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
        //reading number of elements and weight
        int n, w;
        cin>>n>>w;
        
        int val[n];
        int wt[n];
        
        //inserting the values
        for(int i=0;i<n;i++)
            cin>>val[i];
        
        //inserting the weights
        for(int i=0;i<n;i++)
            cin>>wt[i];
        Solution ob;
        //calling method knapSack()
        cout<<ob.knapSack(w, wt, val, n)<<endl;
        
    }
	return 0;
}
// } Driver Code Ends