class Solution {
public:
    map<pair<int, int>, int> dp;
    
    int makeArrayIncreasing(vector<int>& arr1, vector<int>& arr2) {
        dp.clear();
        sort(arr2.begin(),arr2.end());
        int res=helper(0,-1,arr1,arr2);
        return res>=1e9?-1:res;
    }

    int helper(int ind,int prev,vector<int>& arr1, vector<int>& arr2){
        if(ind==arr1.size()) return 0;
        if(dp.find({ind,prev})!=dp.end()) return dp[{ind,prev}];

        int replace=1e9,notReplace=1e9;
        int arr2Index=upper_bound(arr2.begin(),arr2.end(),prev)-arr2.begin();

        if(arr2Index<arr2.size()) replace=1+helper(ind+1,arr2[arr2Index],arr1,arr2);
        if(arr1[ind]>prev) notReplace=helper(ind+1,arr1[ind],arr1,arr2);

        return dp[{ind,prev}]=min(replace,notReplace);
    }
};