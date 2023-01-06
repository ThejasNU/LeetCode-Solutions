class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        
        priority_queue<int,vector<int>,greater<int>> pq{costs.begin(),costs.end()};
        
        int ans=0;
        while(!pq.empty() && coins>=pq.top()){
            ans++;
            coins-=pq.top();
            pq.pop();
        }
        return ans;
    }
};