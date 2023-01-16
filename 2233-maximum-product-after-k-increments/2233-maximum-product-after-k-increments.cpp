class Solution {
public:
    int maximumProduct(vector<int>& nums, int k) {
        int n=nums.size();
        priority_queue<int,vector<int>,greater<int>> pq;
        
        for(int n:nums){
            pq.push(n);
        }
        
        while(!pq.empty() && k>0){
            int cur=pq.top();
            pq.pop();
            pq.push(cur+1);
            k--;
        }
        
        long long ans=1;
        int M=1e9+7;
        while(!pq.empty()){
            int cur=pq.top();
            pq.pop();
            ans*=cur;
            ans%=M;
        }
        
        return ans;
    }
};