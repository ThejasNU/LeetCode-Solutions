class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> adj[numCourses];

        for(auto it:prerequisites){
            adj[it[1]].push_back(it[0]);
        }

        vector<int> indegree(numCourses,0);
        queue<int> q;
        vector<int> ans;

        for(int i=0;i<numCourses;++i){
            for(int v:adj[i]){
                indegree[v]++;
            }
        }

        for(int i=0;i<numCourses;++i){
            if(indegree[i]==0) q.push(i);
        }

        while(!q.empty()){
            int cur=q.front();
            q.pop();
            ans.push_back(cur);

            for(int child:adj[cur]){
                indegree[child]--;
                if(indegree[child]==0) q.push(child);
            }
        }

        if(ans.size()==numCourses) return ans;
        else return {};
    }
};