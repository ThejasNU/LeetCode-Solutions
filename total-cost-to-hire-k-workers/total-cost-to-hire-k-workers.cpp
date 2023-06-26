class Solution {
public:
    long long totalCost(vector<int>& costs, int k, int candidates) {
        long long ans=0;
        //cost,index
        priority_queue<pair<long long,int>,vector<pair<long long,int>>,greater<pair<long long,int>>> pq;
        int l=0,r=costs.size()-1;
        while(l<candidates){
            pq.push({costs[l],l});
            ++l;
        }
        --l;
        while(l<r && candidates){
            pq.push({costs[r],r});
            --r;
            --candidates;
        }
        ++r;

        while(k--){
            ans+=pq.top().first;
            int idx=pq.top().second;
            pq.pop();
            if(idx<=l){
                ++l;
                if(l<r) pq.push({costs[l],l});
            }
            else{
                --r;
                if(l<r) pq.push({costs[r],r});
            }
        }
        return ans;
    }
};