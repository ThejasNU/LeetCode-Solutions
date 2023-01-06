class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        int ans=0;
        map<int,int> m;
        
        for(int cost:costs){
            m[cost]++;
        }
        
        int cost,freq,count;
        for(auto it:m){
            cost=it.first;
            freq=it.second;
            
            if(cost>coins) break;
            
            count=min(m[cost],coins/cost);
            ans+=count;
            coins-=cost*count;
        }
        
        return ans;
    }
};