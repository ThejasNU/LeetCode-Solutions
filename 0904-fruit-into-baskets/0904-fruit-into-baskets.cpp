class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        unordered_map<int,int> basket;
        int maxi=0;
        
        for(int left=0,right=0;right<fruits.size();++right){
            ++basket[fruits[right]];
            while(basket.size()>2){
                --basket[fruits[left]];
                if(basket[fruits[left]]==0) basket.erase(fruits[left]);
                ++left;
            }
            maxi=max(maxi,right-left+1);
        }
        return maxi;
    }
};