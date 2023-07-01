class Solution {
public:
    int distributeCookies(vector<int>& cookies, int k) {
        vector<int> cookieGroup(k,0);
        return helper(0,cookies,k,k,cookieGroup);
    }

    int helper(int idx,vector<int>& cookies, int k,int zeroCount,vector<int>& cookieGroup){
        //if we don't have enough cookies left
        if(cookies.size()-idx<zeroCount) return INT_MAX;
        //if all cookies are distributes return the unfairness
        if(idx==cookies.size()) return *max_element(cookieGroup.begin(),cookieGroup.end());
        int ans=INT_MAX;
        //placing the same cookie in each group and checking the result
        for(int i=0;i<k;++i){
            //reduce zero count since we are gonna add cookie to the group
            if(cookieGroup[i]==0) --zeroCount;
            cookieGroup[i]+=cookies[idx];
            ans=min(ans,helper(idx+1,cookies,k,zeroCount,cookieGroup));
            //backtrack
            cookieGroup[i]-=cookies[idx];
            if(cookieGroup[i]==0) ++zeroCount;
        }
        return ans;
    }
};