class Solution {
public:
    string breakPalindrome(string palindrome) {
        if(palindrome.size()==1) return "";
        
        for(int i=0;i<palindrome.size()/2;++i){
            if(palindrome[i]!='a'){
                palindrome[i]='a';
                return palindrome;
            }
        }
        
        string temp=palindrome.substr(0,palindrome.size()-1);
        temp.push_back('b');
        return temp;
    }
};