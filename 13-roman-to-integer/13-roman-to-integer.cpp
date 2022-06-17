class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char,int> m;
        m['I']=1;
        m['V']=5;
        m['X']=10;
        m['L']=50;
        m['C']=100;
        m['D']=500;
        m['M']=1000;
        
        int sol=0;
        for(int i=0;i<s.size();++i){
            if(m[s[i]]<m[s[i+1]]){
                sol-=m[s[i]];
            }
            else{
               sol+=m[s[i]]; 
            }
        }
        
        return sol;
    }
};