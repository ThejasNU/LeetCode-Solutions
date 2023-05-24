class Solution {
public:
    long long maxScore(vector<int>& nums1, vector<int>& nums2, int k) {
        int n=nums1.size();
        //nums2,nums1
        vector<pair<int,int>> pairs;
        for(int i=0;i<n;++i){
            pairs.push_back({nums2[i],nums1[i]});
        }
        //sort in descending order taking nums2 value into consideration
        sort(pairs.begin(),pairs.end(),[](pair<int,int>& a,pair<int,int>& b){return a.first>b.first;});
        priority_queue<int,vector<int>,greater<int>> pq;
        long long ans=0,sum=0;
        for(auto& it:pairs){
            pq.push(it.second);
            sum+=it.second;
            if(pq.size()>k){
                sum-=pq.top();
                pq.pop();
            }
            if(pq.size()==k) ans=max(ans,sum*it.first);
        }
        return ans;
    }
};