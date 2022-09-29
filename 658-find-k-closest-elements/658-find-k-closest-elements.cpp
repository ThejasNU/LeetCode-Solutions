class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        vector<int> res;
        if(arr.size()==0 || k==0) return res;
        if(k>arr.size()) return res;
        multiset<pair<int,int>> s;
        
        for(int i=0;i<arr.size();++i){
            s.insert({abs(arr[i]-x),arr[i]});
        }
        
        auto it=s.begin();
        for(int j=0;j<k;++j){
            res.push_back(it->second);
            it++;
        }
        sort(res.begin(),res.end());
        return res;
        
    }
};