class DisjointSet {
public:
    vector<int> rank, parent;

    DisjointSet(int n) {
        rank.resize(n, 0);
        parent.resize(n);
        for(int i = 0;i<n;i++) {
            parent[i] = i;
        }
    }

    int find(int node) {
        if(node == parent[node]) return node;

        return parent[node] = find(parent[node]);
    }

    void unionBR(int u, int v) {
        int ulp_u = find(u);
        int ulp_v = find(v);
        if(ulp_u == ulp_v) return;
        if(rank[ulp_u] < rank[ulp_v]) {
            parent[ulp_u] = ulp_v;
        }
        else if(rank[ulp_v] < rank[ulp_u]) {
            parent[ulp_v] = ulp_u;
        }
        else {
            parent[ulp_v] = ulp_u;
            rank[ulp_u]++;
        }
    }

};

class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int n=accounts.size();
        DisjointSet ds(n);
        unordered_map<string,int> m;
        
        for(int i=0;i<n;++i){
            for(int j=1;j<accounts[i].size();++j){
                string mail=accounts[i][j];
                
                if(m.find(mail)!=m.end()) ds.unionBR(m[mail],i);
                else m[mail]=i;
            }
        }
        
        vector<string> mergedMails[n];
        for(auto it:m){
            string mail=it.first;
            int node=ds.find(it.second);
            mergedMails[node].push_back(mail);
        }
        
        vector<vector<string>> ans;
        
        for(int i=0;i<n;++i){
            if(mergedMails[i].size()==0) continue;
            
            sort(mergedMails[i].begin(),mergedMails[i].end());
            mergedMails[i].insert(mergedMails[i].begin(),accounts[i][0]);
            ans.push_back(mergedMails[i]);
        }
        
        return ans;
    }
};