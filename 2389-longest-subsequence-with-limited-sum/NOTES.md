Brute-Force code which gave TLE:
​
```cpp
class Solution {
public:
vector<int> answerQueries(vector<int>& nums, vector<int>& queries) {
vector<int> ans(queries.size(),0);
for(int i=0;i<queries.size();++i){
helper(0,nums,i,queries,ans,0,0);
}
return ans;
}
void helper(int ind,vector<int>& nums,int queryInd, vector<int>& queries,vector<int> &ans,int prevSum,int prevCnt){
if(ind==nums.size()-1){
if(prevSum+nums[ind]<=queries[queryInd]){
ans[queryInd]=max(ans[queryInd],prevCnt+1);
}
else{
ans[queryInd]=max(ans[queryInd],prevCnt);
}
return;
}
//including the current
if(prevSum+nums[ind]<=queries[queryInd]) helper(ind+1,nums,queryInd,queries,ans,prevSum+nums[ind],prevCnt+1);
//excluding the current
helper(ind+1,nums,queryInd,queries,ans,prevSum,prevCnt);
return;
}
};
```