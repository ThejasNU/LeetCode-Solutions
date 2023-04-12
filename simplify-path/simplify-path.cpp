class Solution {
public:
    string simplifyPath(string path) {
        stack<string> st;
        int n=path.size();
        for(int i=0;i<n;++i){
            if(path[i]=='/') continue;

            string temp="";
            while(i<n && path[i]!='/'){
                temp.push_back(path[i]);
                ++i;
            }

            if(temp==".") continue;
            else if(temp==".."){
                if(!st.empty()) st.pop();
            }
            else st.push(temp);
        }
        string ans="";
        while(!st.empty()){
            ans="/"+st.top()+ans;
            st.pop();
        }
        return ans.size()==0 ? "/" : ans;
    }
};