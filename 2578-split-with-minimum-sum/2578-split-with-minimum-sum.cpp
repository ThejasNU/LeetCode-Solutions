class Solution {
public:
    int splitNum(int num) {
        string s=to_string(num);
        sort(s.begin(),s.end());
        int n=s.size();
        string s1="";
        string s2="";
        
        for(int i=0;i<n;i+=2) s1.push_back(s[i]);
        for(int i=1;i<n;i+=2) s2.push_back(s[i]);
        
        return stoi(s1)+stoi(s2);
    }
};