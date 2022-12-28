class Solution {
public:
    int minStoneSum(vector<int>& piles, int k) {
        priority_queue<int> pq;
        for(int num:piles){
            pq.push(num);
        }
        
        while(k--){
            int temp=pq.top();
            pq.pop();
            temp-=(temp/2);
            pq.push(temp);
        }
        
        int ans=0;
        while(!pq.empty()){
            ans+=pq.top();
            pq.pop();
        }
        
        return ans;
    }
};