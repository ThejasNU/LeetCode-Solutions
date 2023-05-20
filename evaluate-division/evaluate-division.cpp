class Solution {
public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        vector<double> ans;
        map<string,double> vals;
        map<string,vector<string>> graph;
        for(int i=0;i<equations.size();i++){
            string u=equations[i][0];
            string v=equations[i][1];
            vals[u+"->"+v]=values[i];
            vals[v+"->"+u]=1/values[i];
            graph[u].push_back(v);
            graph[v].push_back(u);
        }
        for(int i=0;i<queries.size();i++){
            string start=queries[i][0];
            string end=queries[i][1];
            if(graph.find(start)==graph.end()||graph.find(end)==graph.end()){
                ans.push_back(-1);
            }
            else{
                double val=1;
                map<string,bool> visited;
                bool found=false;
                
                if(start==end) found=true;
                else dfs(start,end,vals,graph,val,visited,found);
                
                if(found==true) ans.push_back(val);
                else ans.push_back(-1);
            }
        }
        return ans;
    }

    void dfs(string start,string end,map<string,double>& vals,map<string,vector<string>>& graph,double& val,map<string,bool>& vis,bool& found){
        vis[start]=true;
        if(found) return;
        for(auto child:graph[start]){
            if(vis[child]) continue;
            val*=vals[start+"->"+child];
            if(child==end){
                found=true;
                return;
            }
            dfs(child,end,vals,graph,val,vis,found);
            if(found) return;
            else val/=vals[start+"->"+child];
        }
    }
};