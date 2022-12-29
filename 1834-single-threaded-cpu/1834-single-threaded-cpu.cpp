class Solution {
public:
    vector<int> getOrder(vector<vector<int>>& tasks) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
        
        vector<vector<int>> sortedTasks;
        for(int i=0;i<tasks.size();++i){
            sortedTasks.push_back({tasks[i][0],tasks[i][1],i});
        }
        
        sort(sortedTasks.begin(),sortedTasks.end());
        
        vector<int> ans;
        
        long long curTime=0;
        int taskIndex=0;
        
        while(taskIndex<tasks.size() || !pq.empty()){
            if(pq.empty() && curTime<sortedTasks[taskIndex][0]){
                curTime=sortedTasks[taskIndex][0];
            }
            
            while(taskIndex < sortedTasks.size() && curTime >= sortedTasks[taskIndex][0]){
                pq.push({sortedTasks[taskIndex][1],sortedTasks[taskIndex][2]});
                taskIndex++;
            }
            
            auto it=pq.top();
            pq.pop();
            int processTime=it.first;
            int index=it.second;
            
            curTime+=processTime;
            ans.push_back(index);
        }
        
        return ans;
    }
};