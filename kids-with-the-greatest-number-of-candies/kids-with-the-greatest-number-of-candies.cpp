class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        vector<bool> ans;
        int maxEle= *max_element(candies.begin(),candies.end());
        for(int i=0;i<candies.size();++i){
            candies[i]-=maxEle;
        }
        for(int candiesLeft:candies){
            if(candiesLeft+extraCandies>=0) ans.push_back(true);
            else ans.push_back(false);
        }
        return ans;
    }
};