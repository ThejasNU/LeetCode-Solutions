class UndergroundSystem {
public:
    unordered_map<int,pair<string,int>> cIn;
    unordered_map<string,pair<double,int>> timeDif;
    UndergroundSystem() {
        cIn.clear();
        timeDif.clear();
    }
    
    void checkIn(int id, string stationName, int t) {
        cIn[id]={stationName,t};
    }
    
    void checkOut(int id, string stationName, int t) {
        string res=""+cIn[id].first+"->"+stationName;
        timeDif[res].first+=t-cIn[id].second;
        timeDif[res].second+=1;
        cIn.erase(id);
    }
    
    double getAverageTime(string startStation, string endStation) {
        string key=startStation+"->"+endStation;
        pair<double,int> p=timeDif[key];
        return p.first/p.second;
    }
};

class lessOptimizedUndergroundSystem {
public:
    unordered_map<int,pair<string,int>> cIn;
    unordered_map<string,vector<int>> timeDif;
    lessOptimizedUndergroundSystem() {
        cIn.clear();
        timeDif.clear();
    }
    
    void checkIn(int id, string stationName, int t) {
        cIn[id]={stationName,t};
    }
    
    void checkOut(int id, string stationName, int t) {
        string res=""+cIn[id].first+"->"+stationName;
        timeDif[res].push_back(t-cIn[id].second);
    }
    
    double getAverageTime(string startStation, string endStation) {
        string key=startStation+"->"+endStation;
        vector<int> v=timeDif[key];
        int sum=accumulate(v.begin(),v.end(),0);
        return (double)sum/(double)v.size();
    }
};

/**
 * Your UndergroundSystem object will be instantiated and called as such:
 * UndergroundSystem* obj = new UndergroundSystem();
 * obj->checkIn(id,stationName,t);
 * obj->checkOut(id,stationName,t);
 * double param_3 = obj->getAverageTime(startStation,endStation);
 */