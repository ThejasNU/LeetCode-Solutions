class Solution {
public:
    bool wordPattern(string pattern, string s) {
        vector<string> words;
        string str="";
        for(int i=0;i<s.size();++i){
            if(s[i]==' '){
                words.push_back(str);
                str="";
            }
            else if(i== s.size()-1){
                str.push_back(s[i]);
                words.push_back(str);
            }
            else{
                str.push_back(s[i]);
            }
        }
        if(pattern.size()!=words.size()){
            return false;
        }
        map<char,string> m;
        for(int j=0;j<pattern.size();++j){
            if(m[pattern[j]]==""){
                m[pattern[j]]=words[j];
            }
            else{
                if(m[pattern[j]]!=words[j]){
                    return false;
                }
            }
        }
        
        vector<string> contents;
        for(auto ele:m){
            contents.push_back(ele.second);
        }
        
        for(int k=0;k<contents.size()-1;++k){
            for(int l=k+1;l<contents.size();++l){
                if(contents[k]==contents[l]){
                    return false;
                }
            }
        }
        
        return true;
    }
};