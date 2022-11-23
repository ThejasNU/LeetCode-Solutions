class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> adj[numCourses];

        for(auto it:prerequisites){
            adj[it[1]].push_back(it[0]);
        }

        vector<int> indegree(numCourses,0);
        queue<int> q;
        int count=0;

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
            count++;

            for(int child:adj[cur]){
                indegree[child]--;
                if(indegree[child]==0) q.push(child);
            }
        }

        return count==numCourses;
    }
};