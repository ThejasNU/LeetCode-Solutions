class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start, int end) {
        unordered_map<int, vector<pair<int, int>>> graph;
        for (int i = 0; i < edges.size(); i++) {
            int u = edges[i][0], v = edges[i][1], edgeIdx = i;
            graph[u].push_back({v, edgeIdx});
            graph[v].push_back({u, edgeIdx});
        }
        
        vector<double> probabilities(n, 0.0);
        probabilities[start] = 1.0;
        
        priority_queue<pair<double, int>> nodesToExplore;
        nodesToExplore.push({1.0, start});
        
        while (!nodesToExplore.empty()) {
            auto [prob, u] = nodesToExplore.top();
            nodesToExplore.pop();
            
            if (u == end) return prob;
            if (probabilities[u] > prob) continue;
                
            for (auto [v, edgeIdx] : graph[u]) {
                double newProb = prob * succProb[edgeIdx];
                if (newProb > probabilities[v]) {
                    probabilities[v] = newProb;
                    nodesToExplore.push({newProb, v});
                }
            }
        }
        
        return probabilities[end];
    }
};

class altSolution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start, int end) {
        vector<vector<pair<int, double>>> adj(n);
        for (int i = 0; i < edges.size(); i++) {
            int u = edges[i][0];
            int v = edges[i][1];
            adj[u].push_back({v, succProb[i]});
            adj[v].push_back({u, succProb[i]});
        }

        vector<double> probs(n, 0.0);
        probs[start] = 1.0;
        
        queue<int> q;
        q.push(start);
        
        while (!q.empty()) {
            int curr = q.front();
            q.pop();
            
            for (auto x : adj[curr]) {
                int node = x.first;
                double prob = x.second;
                double newProb = probs[curr] * prob;
                
                if (newProb > probs[node]) {
                    probs[node] = newProb;
                    q.push(node);
                }
            }
        }
        
        return probs[end];
    }
};