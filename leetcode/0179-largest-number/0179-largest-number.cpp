class Solution {
public:
    string largestNumber(vector<int>& nums) {
        priority_queue<string,vector<string>,decltype(&compare)> pq(&compare);
        
        for(int num:nums){
            pq.push(to_string(num));
        }

        string ans="";
        while(!pq.empty()){
            ans+=pq.top();
            pq.pop();
        }

        if(ans.empty() || ans[0]=='0'){
            return "0";
        }
        
        return ans;
    }

    static bool compare(const string& s1,const string& s2){
        return (s2+s1) > (s1+s2);
    }
};