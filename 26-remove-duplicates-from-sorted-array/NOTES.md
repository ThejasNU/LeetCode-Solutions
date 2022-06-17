Optimal Solution:
​
```
int removeDuplicates(vector<int>& nums) {
​
int c = 1; // counter variable
for(int i = 1; i < nums.size(); i++){
if(nums[i] != nums[i-1]){    // if element of arr[1] != arr[0] so on
nums[c] = nums[i];
c++;
}
}
nums.resize(c);    // resize the size of array
return nums.size();   // return new size of array
}
```