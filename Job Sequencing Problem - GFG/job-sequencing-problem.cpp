//{ Driver Code Starts
// Program to find the maximum profit job sequence from a given array 
// of jobs with deadlines and profits 
#include<bits/stdc++.h>
using namespace std; 

// A structure to represent a job 
struct Job 
{ 
    int id;	 // Job Id 
    int dead; // Deadline of job 
    int profit; // Profit if job is over before or on deadline 
}; 


// } Driver Code Ends
/*
struct Job 
{ 
    int id;	 // Job Id 
    int dead; // Deadline of job 
    int profit; // Profit if job is over before or on deadline 
};
*/

class Solution 
{
    public:
    //Function to find the maximum profit and the number of jobs done.
    vector<int> JobScheduling(Job arr[], int n) { 
        sort(arr,arr+n,comp);
        
        int maxDeadline=0;
        for(int i=0;i<n;++i){
            maxDeadline=max(maxDeadline,arr[i].dead);
        }
        vector<int> jobAssigned(maxDeadline,-1);
        int profits=0,num=0;
        for(int i=0;i<n;++i){
            int deadline=arr[i].dead;
            deadline-=1;
            while(deadline>=0 && jobAssigned[deadline]!=-1) deadline--;
            
            if(deadline>=0){
                jobAssigned[deadline]=arr[i].id;
                num++;
                profits+=arr[i].profit;
            }
        }
        
        vector<int> ans(2);
        ans[0]=num;
        ans[1]=profits;
        return ans;
    }
    
    static bool comp(Job a,Job b){
        return a.profit>b.profit;
    }
};

//{ Driver Code Starts.
// Driver program to test methods 
int main() 
{ 
    int t;
    //testcases
    cin >> t;
    
    while(t--){
        int n;
        
        //size of array
        cin >> n;
        Job arr[n];
        
        //adding id, deadline, profit
        for(int i = 0;i<n;i++){
                int x, y, z;
                cin >> x >> y >> z;
                arr[i].id = x;
                arr[i].dead = y;
                arr[i].profit = z;
        }
        Solution ob;
        //function call
        vector<int> ans = ob.JobScheduling(arr, n);
        cout<<ans[0]<<" "<<ans[1]<<endl;
    }
	return 0; 
}



// } Driver Code Ends