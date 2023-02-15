class Solution {
public:
    vector<int> addToArrayForm(vector<int>& num, int k) {
        int i=num.size()-1;
        while(i>=0 && k>0){
            num[i]+=k;
            k=num[i]/10;
            num[i]%=10;
            --i;
        }
        while(k>0){
            num.insert(num.begin(),k%10);
            k/=10;
        }
        return num;
    }
};