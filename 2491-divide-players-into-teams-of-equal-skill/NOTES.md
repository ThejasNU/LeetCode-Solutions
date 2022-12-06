```
/*
Approach :
Keep on checking if the complimetary value is already seen or not, if seen then simply
reduce the count of the complimentary one and calculate the result.
​
To check if all the elements are metched or not a count can be used to see it is equal to zero or not.
count can be increament when a match found and decremented when not found.
*/
long long dividePlayers(vector<int>& skill) {
long long ans = 0;
unordered_map<int, int> mp;
long sum = 0, count = 0, n = skill.size()/2;
for(auto s: skill) sum+= s;
if(sum % n != 0) return -1;
int teamSize = sum/n;
for(auto s: skill){
if(mp[teamSize - s] > 0 ){
mp[teamSize - s]--;
ans += s * (teamSize - s);
count--;
}else{
mp[s]++; count++;
}
}
if(count != 0 ) return -1;
return ans;
}
```