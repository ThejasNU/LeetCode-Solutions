class Solution{
public:
    vector<vector<int>> dp;

    int tallestBillboard(vector<int>& rods){
        int n=rods.size();
        dp.resize(n,vector<int>(10001,-1));
        return helper(0,0,rods)/2;
    }

    int helper(int idx,int dif,vector<int>& rods){
        if(idx==rods.size()){
            if(dif==0) return 0;
            else return -1e5;
        }
        if(dp[idx][dif+5000]!=-1) return dp[idx][dif+5000];

        //don't put anywhere
        int ans=helper(idx+1,dif,rods);
        //put in 1st set
        ans=max(ans,rods[idx]+helper(idx+1,dif+rods[idx],rods));
        //put in 2nd set
        ans=max(ans,rods[idx]+helper(idx+1,dif-rods[idx],rods));

        return dp[idx][dif+5000]=ans;
    }
};

class tleSolution {
public:
    int ans;
    
    int tallestBillboard(vector<int>& rods) {
        ans=0;
        helper(0,0,0,rods);
        return ans;
    }

    void helper(int idx,int len1,int len2,vector<int>& rods){
        if(idx==rods.size()){
            if(len1==len2){
                ans=max(ans,len1);
            }
            return;
        }

        //don't put in any set
        helper(idx+1,len1,len2,rods);
        //put in 1st set
        helper(idx+1,len1+rods[idx],len2,rods);
        //put in 2nd set
        helper(idx+1,len1,len2+rods[idx],rods);
    }


};