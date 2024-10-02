class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        map<int,vector<int>>m;
        for(int i=0;i<arr.size();++i){
            m[arr[i]].push_back(i);
        }

        vector<int> ans(arr.size());
        int rank=1;
        for(auto& [num,indices]:m){
            for(int index:indices){
                ans[index]=rank;
            }
            ++rank;
        }

        return ans;
    }
};