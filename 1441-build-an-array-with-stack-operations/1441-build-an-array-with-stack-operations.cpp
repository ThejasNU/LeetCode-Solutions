class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {
        vector<string> ans;
        auto it=target.begin();
        
        for(int i=1;i<=n;++i){
            if(i==*it){
                ans.push_back("Push");
                it++;
                if(it==target.end()){
                    break;
                }
            }
            else{
                ans.push_back("Push");
                ans.push_back("Pop");
            }
        }
        return ans;
        
    }
};