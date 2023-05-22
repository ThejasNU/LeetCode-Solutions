

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        if(k==nums.size()) return nums;

        map<int,int> m;
        for(int n:nums){
            ++m[n];
        }

        priority_queue<pair<int,int>> pq;
        for(auto it:m){
            pq.push({it.second,it.first});
        }

        vector<int> ans;
        while(k--){
            ans.push_back(pq.top().second);
            pq.pop();
        }
        return ans;
    }
};