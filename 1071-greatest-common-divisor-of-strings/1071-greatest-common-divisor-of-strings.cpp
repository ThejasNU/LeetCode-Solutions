class Solution {
public:
    string gcdOfStrings(string str1, string str2) {
        int l1=str1.size(),l2=str2.size();
        if(str1+str2!=str2+str1) return "";
        
        int gcdLen=gcd(l1,l2);
        return str1.substr(0,gcdLen);
    }
};


class bruteForceSolution {
public:
    string gcdOfStrings(string str1, string str2) {
        int l1=str1.size(),l2=str2.size();
        
        for(int i=min(l1,l2);i>=1;--i){
            if(check(str1,str2,i)) return str1.substr(0,i);
        }
        return "";
    }
    
    bool check(string s1,string s2,int len){
        int l1=s1.size(),l2=s2.size();
        
        if(l1%len>0 || l2%len>0) return false;
        else{
            string base=s1.substr(0,len);
            int n1=l1/len,n2=l2/len;
            return s1==joinWords(base,n1) && s2==joinWords(base,n2);
        }
    }
    
    string joinWords(string s,int k){
        string ans="";
        while(k--){
            ans+=s;
        }
        return ans;
    }
};