Interview type answer which gives TLE on leetcode but not on GFG:
​
```cpp
class Solution {
public:
vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
unordered_set<string> s(wordList.begin(),wordList.end());
queue<vector<string>> q;
q.push({beginWord});
vector<string> usedOnLevel;
usedOnLevel.push_back(beginWord);
int level=0;
vector<vector<string>> ans;
while(!q.empty()){
vector<string> vec=q.front();
q.pop();
if(vec.size()>level){
level++;
for(auto it:usedOnLevel){
s.erase(it);
}
}
string cur=vec.back();
if(cur==endWord){
if(ans.size()==0) ans.push_back(vec);
else if(ans[0].size()==vec.size()) ans.push_back(vec);
}
q.push(vec);