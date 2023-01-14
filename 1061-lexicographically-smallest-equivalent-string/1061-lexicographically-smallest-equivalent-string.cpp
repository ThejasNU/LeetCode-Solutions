class DisjointSet {
public:
    vector<int> parent;

    DisjointSet(int n) {
        parent.resize(n);
        for(int i = 0;i<n;i++) {
            parent[i] = i;
        }
    }

    int find(int node) {
        if(node == parent[node]) return node;

        return parent[node] = find(parent[node]);
    }

    void unioN(int u, int v) {
        int ulp_u = find(u);
        int ulp_v = find(v);
        if(ulp_u == ulp_v) return;
        if(ulp_u < ulp_v) {
            parent[ulp_v] = ulp_u;
        }
        else if(ulp_v <ulp_u) {
            parent[ulp_u] = ulp_v;
        }
    }
};

class Solution {
public:
    string smallestEquivalentString(string s1, string s2, string baseStr) {
        int n=s1.size();
        DisjointSet ds(26);
        
        for(int i=0;i<n;++i){
            int n1=s1[i]-'a';
            int n2=s2[i]-'a';
            ds.unioN(n1,n2);
        }
        
        string ans="";
        for(char c:baseStr){
            int par=ds.find(c-'a');
            ans.push_back('a'+par);
        }
        
        return ans;
    }
};