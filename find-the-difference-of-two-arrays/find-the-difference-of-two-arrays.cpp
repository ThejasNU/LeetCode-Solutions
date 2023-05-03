class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        vector<vector<int>> ans;
        ans.push_back(helper(nums1,nums2));
        ans.push_back(helper(nums2,nums1));
        return ans;
    }
    
    vector<int> helper(vector<int>& nums1, vector<int>& nums2){
        unordered_set<int> set1;
        unordered_set<int> set2;
        for(int num:nums2){
            set2.insert(num);
        }

        for(int num:nums1){
            if(set2.find(num)==set2.end()) set1.insert(num);
        }
        return vector<int>(set1.begin(),set2.end());
    }
};