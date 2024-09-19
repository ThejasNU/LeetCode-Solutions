class Solution {
public:
    vector<int> diffWaysToCompute(string expression) {
        vector<int> ans;

        switch (expression.size()){
            case 0:
                return ans;
            case 1:
                ans.push_back(stoi(expression));
                return ans;
            case 2:
                if(isdigit(expression[0])){
                    ans.push_back(stoi(expression));
                    return ans;
                }
        }

        for(int i=0;i<expression.size();++i){
            char c=expression[i];
            
            if(isdigit(c)){
                continue;
            }

            vector<int> leftRes = diffWaysToCompute(expression.substr(0,i));
            vector<int> rightRes = diffWaysToCompute(expression.substr(i+1));

            for(int l:leftRes){
                for(int r:rightRes){
                    int res = 0;

                    switch (c) {
                        case '+':
                            res = l + r;
                            break;
                        case '-':
                            res = l - r;
                            break;
                        case '*':
                            res = l * r;
                            break;
                    }

                    ans.push_back(res);
                }
            }
        }

        return ans;
    }
};