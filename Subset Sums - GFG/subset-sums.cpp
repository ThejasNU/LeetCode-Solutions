//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
class Solution
{
public:
    vector<int> subsetSums(vector<int> arr, int N){
        sort(arr.begin(),arr.end());
        vector<int> ans;
        helper(0,arr,N,0,ans);
        return ans;
    }
    
    void helper(int ind,vector<int> &arr, int N,int sum,vector<int> &ans){
        if(ind==N){
            ans.push_back(sum);
            return;
        }
        
        helper(ind+1,arr,N,sum,ans);
        
        helper(ind+1,arr,N,sum+arr[ind],ans);
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N;
        cin>>N;
        vector<int> arr(N);
        for(int i = 0 ; i < N ; i++){
            cin >> arr[i];
        }
        Solution ob;
        vector<int> ans = ob.subsetSums(arr,N);
        sort(ans.begin(),ans.end());
        for(auto sum : ans){
            cout<< sum<<" ";
        }
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends