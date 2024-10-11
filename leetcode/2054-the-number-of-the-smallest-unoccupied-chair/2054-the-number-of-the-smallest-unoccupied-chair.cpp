class Solution {
public:
    int smallestChair(vector<vector<int>>& times, int targetFriend) {
        int n = times.size();

        vector<pair<int,int>> events;
        for(int i=0;i<n;++i){
            events.push_back({times[i][0],i});
            events.push_back({times[i][1],~i});
        }
        sort(events.begin(),events.end());

        priority_queue<int,vector<int>, greater<int>> available;
        priority_queue<pair<int,int>,vector<pair<int,int>>, greater<pair<int,int>>> occupied;

        for(int i=0;i<n;++i){
            available.push(i);
        }

        for(auto& event:events){
            int time = event.first;
            int idx = event.second;

            while(!occupied.empty() && occupied.top().first<=time){
                int chair = occupied.top().second;
                occupied.pop();
                
                available.push(chair);
            }

            if(idx>=0){
                int chair = available.top();
                available.pop();

                if(idx==targetFriend){
                    return chair;
                }

                occupied.push({times[idx][1],chair});
            }
        }

        return -1;
    }
};