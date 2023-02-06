class Solution {
public:
    vector<int> shuffle(vector<int>& nums, int n) {
        //number with 0's followed by 10 1's
        int allOnes=pow(2,10)-1;
        //storing 2 numbers last 10 bits is first number and before that 10 bits are second number
        for(int i=n;i<2*n;++i){
            int secondNumber=nums[i]<<10;
            nums[i-n]|=secondNumber;
        }
        
        for(int i=n-1;i>=0;--i){
            int secondNumber=nums[i]>>10;
            int firstNumber=nums[i]&allOnes;
            cout<<firstNumber<<" "<<secondNumber<<endl;
            nums[2*i+1]=secondNumber;
            nums[2*i]=firstNumber;
        }
        return nums;
    }
};

class Solution {
public:
    vector<int> shuffle(vector<int>& nums, int n) {
        vector<int> res;
        
        for(int i=0;i<n;++i){
            res.push_back(nums[i]);
            res.push_back(nums[n+i]);
        }
        
        return res;
        
    }
};
