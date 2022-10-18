class Solution {
public:
    string countAndSay(int n) {
        string res="1";
        
        while(--n){
            string s="";
            for(int i=0;i<res.size();i++){
                int count = 1;
                while(i+1<res.size() && res[i]==res[i+1]){
                    ++count;
                    i++;
                }
                s.push_back(count+'0');
                s.push_back(res[i]);
            }
                res=s;
        }
        return res;
    }
};