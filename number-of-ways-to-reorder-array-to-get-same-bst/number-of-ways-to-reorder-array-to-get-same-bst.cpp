class Solution {
public:
    vector<vector<long long>> table;
    long long M=1e9+7;

    int numOfWays(vector<int>& nums) {
        int n=nums.size();
        table.resize(n+1);
        
        for(int i=0;i<n+1;++i){
            table[i]=vector<long long>(i+1,1);
            for(int j=1;j<i;++j){
                table[i][j]=(table[i-1][j-1]+table[i-1][j])%M;
            }
        }
        return (helper(nums)-1)%M;
    }

    long long helper(vector<int>& nums){
        int n=nums.size();
        if(n<3) return 1;

        vector<int> leftNodes,rightNodes;
        for(int i=1;i<n;++i){
            if(nums[i]<nums[0]) leftNodes.push_back(nums[i]);
            else rightNodes.push_back(nums[i]);
        }

        long long leftWays=helper(leftNodes)%M;
        long long rightWays=helper(rightNodes)%M;

        return (((leftWays*rightWays)%M)*table[n-1][leftNodes.size()])%M;
    }
};