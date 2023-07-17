//{ Driver Code Starts
// Initial Template for c++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int palindromicPartition(string str){
        int n=str.size();
        vector<int> dp(n+1,-1);
        dp[n]=0;
        
        for(int i=n-1;i>=0;--i){
            int ans=INT_MAX;
            for(int j=i;j<n;++j){
                if(isPalindrome(str,i,j)){
                    ans=min(ans,1+dp[j+1]);
                }
            }
            dp[i]=ans;
        }
        return dp[0]-1;
    }
    
    bool isPalindrome(const string& str,int low,int high){
        while(low<high){
            if(str[low++]!=str[high--]) return false;
        }
        return true;
    }
};

class topDownSolution{
public:
    int palindromicPartition(string str){
        int n=str.size();
        vector<int> dp(n,-1);
        //since it does extra partition after reaching the end we have to ignore that
        return helper(0,str,dp)-1;
    }
    
    int helper(int start,const string& str,vector<int>& dp){
        if(start>=str.size()) return 0;
        if(dp[start]!=-1) return dp[start];
        
        int ans=INT_MAX;
        for(int i=start;i<str.size();++i){
            if(isPalindrome(str,start,i)){
                ans=min(ans,1+helper(i+1,str,dp));
            }
        }
        return dp[start]=ans;
    }
    
    bool isPalindrome(const string& str,int low,int high){
        while(low<high){
            if(str[low++]!=str[high--]) return false;
        }
        return true;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        string str;
        cin>>str;
        
        Solution ob;
        cout<<ob.palindromicPartition(str)<<"\n";
    }
    return 0;
}
// } Driver Code Ends