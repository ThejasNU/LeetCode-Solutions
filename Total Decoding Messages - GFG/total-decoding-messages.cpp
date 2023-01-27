//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
	public:
	    vector<long long> dp;
	    int M=1e9+7;
		int CountWays(string str){
		    dp.resize(str.size(),-1);
		    helper(0,str);
		    return dp[0]%M;
		}
		
		long long helper(int ind,string &str){
		    int n=str.size();
		    if(ind==n) return 1;
		    if(dp[ind]!=-1) return dp[ind];
		    
		    long long ways=0;
		    if(str[ind]!='0') ways+=helper(ind+1,str);
		    if(ind+1<n && str[ind]!='0' && stoi(str.substr(ind,2))>0 && stoi(str.substr(ind,2))<=26) ways+=helper(ind+2,str);
		    
		    return dp[ind]=ways%M;
		}

};


//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string str;
		cin >> str;
		Solution obj;
		int ans = obj.CountWays(str);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends