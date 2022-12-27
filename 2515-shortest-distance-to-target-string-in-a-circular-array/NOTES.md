Brute Force Code:
​
```cpp
class Solution {
public:
int closetTarget(vector<string>& words, string target, int startIndex) {
int n=words.size();
if(words[startIndex]==target) return 0;
int ans=INT_MAX;
//searching towards right
int i=(startIndex+1)%n;
int count=1;
while(i!=startIndex){
if(words[i]==target){
ans=min(ans,count);
break;
}
i++;
i=i%n;
count++;
}
if(i==startIndex) return -1;
//searching towards left
i=(startIndex-1+n)%n;
count=1;
while(i!=startIndex){
if(words[i]==target){
ans=min(ans,count);
break;
}
i=(i-1+n)%n;
count++;
}
return ans;
}
};
```