class Solution {
public:
    string interpret(string command) {
        string res;
        for(int i =0;i<command.size();++i){
            if(command[i]=='G'){
                res.push_back('G');
            }
            else if(command[i]=='(' && command[i+1]==')'){
                res.push_back('o');
            }
            else if(command[i]=='(' && command[i+1]=='a'){
                res.push_back('a');
                res.push_back('l');
                i=i+2;
            }
            else{
                continue;
            }
        }
        return res;
    }
};