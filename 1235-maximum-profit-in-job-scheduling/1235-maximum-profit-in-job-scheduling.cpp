class Solution {
public:
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        int n = startTime.size();
        int dp[n] ;
        vector<pair<int, pair<int,int>>> jobs(n);
        
        //jobs = [ [endTime[0], [startTime[0], profit[0]]]..... .........[endTime[n],[startTime[n], profit[n]]]]
    
        for(int i = 0; i<n; i++){  
            jobs[i].first = endTime[i];
            jobs[i].second.first = startTime[i];
            jobs[i].second.second = profit[i];
        }
        

        //sort it according to the endTime of each job
        sort(jobs.begin(), jobs.end()); 
        
        for(int i = 0; i<n; i++){
            if(i==0){
                dp[i] = jobs[i].second.second;
                continue;
            }
            int intermediate_profit = 0;
            int j = i-1;
        //check if any job already processed which started in-between while the present job was executing.
            while(j >= 0){
                if(jobs[j].first <= jobs[i].second.first){
                    intermediate_profit = dp[j];
                    break;
                }
                j--;
            }
            dp[i] = max(dp[i-1], intermediate_profit+jobs[i].second.second);
        }
        return dp[n-1];
    }
};