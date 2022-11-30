//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
    public:
    string findOrder(string dict[], int N, int K) {
        vector<int> adj[K];
        int m,l;
        for(int i=0;i<N-1;++i){
            m=0;
            l=min(dict[i].size(),dict[i+1].size());
            while(m<l && dict[i][m]==dict[i+1][m]) m++;
            
            if(m<l) adj[dict[i][m]-'a'].push_back(dict[i+1][m]-'a');
        }
        
        vector<int> order=topoSort(K,adj);
        string ans="";
        
        for(int n:order){
            ans.push_back('a'+n);
        }
        
        return ans;
    }
    
    vector<int> topoSort(int V, vector<int> adj[]){
	   vector<int> indegree(V,0);
	   queue<int> q;
	   vector<int> ans;
	   
	   for(int i=0;i<V;++i){
	       for(int v:adj[i]){
	           indegree[v]++;
	       }
	   }
	   
	   for(int i=0;i<V;++i){
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
	   return ans;
	    
	}
};

//{ Driver Code Starts.
string order;
bool f(string a, string b) {
    int p1 = 0;
    int p2 = 0;
    for (int i = 0; i < min(a.size(), b.size()) and p1 == p2; i++) {
        p1 = order.find(a[i]);
        p2 = order.find(b[i]);
        //	cout<<p1<<" "<<p2<<endl;
    }

    if (p1 == p2 and a.size() != b.size()) return a.size() < b.size();

    return p1 < p2;
}

// Driver program to test above functions
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, K;
        cin >> N >> K;
        string dict[N];
        for (int i = 0; i < N; i++) cin >> dict[i];
        
        Solution obj;
        string ans = obj.findOrder(dict, N, K);
        order = "";
        for (int i = 0; i < ans.size(); i++) order += ans[i];

        string temp[N];
        std::copy(dict, dict + N, temp);
        sort(temp, temp + N, f);

        bool f = true;
        for (int i = 0; i < N; i++)
            if (dict[i] != temp[i]) f = false;

        if(f)cout << 1;
        else cout << 0;
        cout << endl;
    }
    return 0;
}

// } Driver Code Ends