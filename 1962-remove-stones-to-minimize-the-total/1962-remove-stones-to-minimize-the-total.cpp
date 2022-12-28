class Solution {
public:
    int minStoneSum(vector<int>& piles, int k) {
        priority_queue<int> pq(piles.begin(),piles.end());
        
        int ans=accumulate(piles.begin(),piles.end(),0);
        
        while(k--){
            int temp=pq.top();
            pq.pop();
            ans-=(temp/2);
            temp-=(temp/2);
            pq.push(temp);
        }
        
        return ans;
    }
};