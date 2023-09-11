class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& groupSizes) {
        vector<vector<int>> ans;

        vector<vector<int>> bucket(groupSizes.size()+1);

        for(int i=0;i<groupSizes.size();++i){
            bucket[groupSizes[i]].push_back(i);

            if(bucket[groupSizes[i]].size()==groupSizes[i]){
                ans.push_back(bucket[groupSizes[i]]);
                bucket[groupSizes[i]].clear();
            }
        }

        return ans;
    }
};