class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        int m=nums1.size();
        int n=nums2.size();
        
        set<pair<int,int>> vis;
        
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>> pq;
        
        vector<vector<int>> ans;

        pq.push({nums1[0]+nums2[0],{0,0}});
        vis.insert({0,0});
        
        int idx1,idx2;
        while(k-- && !pq.empty()){
            idx1=pq.top().second.first;
            idx2=pq.top().second.second;
            pq.pop();
            ans.push_back({nums1[idx1],nums2[idx2]});
            
            if(idx1+1<m && vis.find({idx1+1,idx2})==vis.end()){
                pq.push({nums1[idx1+1]+nums2[idx2],{idx1+1,idx2}});
                vis.insert({idx1+1,idx2});
            }
            if(idx2+1<n && vis.find({idx1,idx2+1})==vis.end()){
                pq.push({nums1[idx1]+nums2[idx2+1],{idx1,idx2+1}});
                vis.insert({idx1,idx2+1});
            }
        }
        
        return ans;
    }
};