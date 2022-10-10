class Solution {
public:
    string breakPalindrome(string palindrome) {
        if(palindrome.size()==1) return "";
        
        //iterating half of the string is enough, if we iterate whole string we won't get answer
        for(int i=0;i<palindrome.size()/2;++i){
            if(palindrome[i]!='a'){
                palindrome[i]='a';
                return palindrome;
            }
        }
        
        //if all chars till half of the string are a's,then replace last element with b take aba as example or aaaa
        string temp=palindrome.substr(0,palindrome.size()-1);
        temp.push_back('b');
        return temp;
    }
};