//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution
{
    public:
    //Function to perform case-specific sorting of strings.
    string caseSort(string str, int n){
        vector<int> isLower(n,0);
        string lower="";
        string upper="";
        
        for(int i=0;i<n;++i){
            if(str[i]>='a' && str[i]<='z'){
                isLower[i]=1;
                lower.push_back(str[i]);
            }
            else{
                upper.push_back(str[i]);
            }
        }
        
        sort(lower.begin(),lower.end());
        sort(upper.begin(),upper.end());
        
        string ans="";
        int lInd=0;
        int uInd=0;
        for(int i=0;i<n;++i){
            if(isLower[i]){
                ans.push_back(lower[lInd]);
                ++lInd;
            }
            else{
                ans.push_back(upper[uInd]);
                ++uInd;
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		string str;
		cin>>str;
		Solution obj;
		cout<<obj.caseSort (str, n)<<endl;
	}
}
// } Driver Code Ends