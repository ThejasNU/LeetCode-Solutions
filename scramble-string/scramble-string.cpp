class Solution {
public:
    unordered_map<string,bool> m;
    bool isScramble(string s1, string s2) {
        return helper(s1,s2);
    }

    bool helper(string s1,string s2){
        if(s1.length()!=s2.length()){
            return false;
        }
        if(s1.size()==0&&s2.size()==0){
            return true;
        }
        if(s1.compare(s2)==0){
            return true;
        }
        if(s1.length()<=1){
            return false;
        }
        string key = s1+" "+s2;
        if(m.find(key)!=m.end()){
            return m[key];
        }
        bool ans = false;
        int n = s1.length();
        for(int i = 1; i < n; i++){
            if(helper(s1.substr(0,i),s2.substr(n-i)) && helper(s1.substr(i,n-i),s2.substr(0,n-i))){
                ans = true;
            }
            if(!ans && helper(s1.substr(0,i),s2.substr(0,i)) && helper(s1.substr(i,n-i),s2.substr(i,n-i))){
                ans = true;
            }
        }
        return m[key] = ans;
    }
};
