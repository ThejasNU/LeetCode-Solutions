class Solution {
public:
    static bool sortHelper(pair<int,string> a,pair<int,string> b){
        if(a.first>b.first) return true;
        else if(b.first>a.first) return false;
        else{
            return a.second<b.second;
        }
    }
    
    
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string,int> m;
        
        for(int i=0;i<words.size();++i){
            m[words[i]]++;
        }
        
        vector<pair<int,string>> pq;
        
        for(auto it:m){
            pq.push_back({it.second,it.first});
        }
        
        sort(pq.begin(),pq.end(),sortHelper);
        
        for(int i=0;i<pq.size();++i){
            cout<<pq[i].first<<" "<<pq[i].second<<endl;
        }
        
        vector<string> ans;
        
        int i=0;
        while(k--){
            ans.push_back(pq[i].second);
            i++;
        }
        
        return ans;
    }
};