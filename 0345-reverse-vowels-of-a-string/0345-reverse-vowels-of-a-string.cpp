class Solution {
public:
    string reverseVowels(string s) {
        int low=0;
        int high=s.size()-1;
        unordered_set<char> st={'a','e','i','o','u','A','E','I','O','U'};
        while(low<high){
            if(st.count(s[low]) && st.count(s[high])){
                swap(s[low],s[high]);
                low++;
                high--;
            }
            else if(st.count(s[low]) && !st.count(s[high])){
                high--;
            }
            else{
                low++;
            }
        }

        return s;
    }
};