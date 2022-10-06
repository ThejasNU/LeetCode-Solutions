class TimeMap {

    private:
        unordered_map<string, vector<pair<int, string>>> m;
    public:
    TimeMap() {
    }
    
    void set(string key, string value, int timestamp) {
        m[key].push_back({timestamp,value});
    }
    
    string get(string key, int timestamp) {
        if(m.find(key)==m.end()) return "";
        
        if(timestamp<m[key][0].first) return "";
        
        int left = 0;
        int right = m[key].size();
        
        while (left < right) {
            int mid = (left + right) / 2;
            if (m[key][mid].first <= timestamp) {
                left = mid + 1;
            } else {
                right = mid;
            }
        }
        
        if(right==0) return "";
        else return m[key][right-1].second;
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */