//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
    public:
    //Function to find the maximum number of meetings that can
    //be performed in a meeting room.
    int maxMeetings(int start[], int end[], int n){
        
        //endtime,position,starttime
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>> pq;

        for(int i=0;i<n;++i){
            pq.push({end[i],{i+1,start[i]}});
        }
        
        int limit=pq.top().first;
        int ans=1;
        pq.pop();
        
        while(!pq.empty()){
            int startTime=pq.top().second.second;
            int endTime=pq.top().first;
            if(startTime>limit){
                limit=endTime;
                ans++;
            }
            pq.pop();
        }
        
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int start[n], end[n];
        for (int i = 0; i < n; i++) cin >> start[i];

        for (int i = 0; i < n; i++) cin >> end[i];

        Solution ob;
        int ans = ob.maxMeetings(start, end, n);
        cout << ans << endl;
    }
    return 0;
}
// } Driver Code Ends