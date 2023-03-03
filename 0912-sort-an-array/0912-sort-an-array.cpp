class Solution{
public:
    vector<int> sortArray(vector<int> &nums){
        radixSort(nums);
        return nums;
    }
    
    void radixSort(vector<int> &nums){
        int maxElement = nums[0];
        for (int num : nums) {
            maxElement = max(abs(num), maxElement);
        }
        int maxDigits=0;
        while(maxElement>0){
            ++maxDigits;
            maxElement/=10;
        }
        
        int placeValue=1;
        for(int digit=0;digit<maxDigits;++digit){
            bucketSort(nums,placeValue);
            placeValue*=10;
        }
        
        vector<int> negatives,positives;
        for(int num:nums){
            if(num<0) negatives.push_back(num);
            else positives.push_back(num);
        }
        
        reverse(negatives.begin(),negatives.end());
        merge(negatives.begin(), negatives.end(), positives.begin(), positives.end(), nums.begin());
    }
    
    void bucketSort(vector<int> &nums,int placeValue){
        vector<vector<int>> buckets(10,vector<int>());
        
        for(int num:nums){
            int digit=abs(num)/placeValue;
            digit=digit%10;
            buckets[digit].push_back(num);
        }
        
        int i=0;
        for(int digit=0;digit<10;++digit){
            for(int val:buckets[digit]){
                nums[i]=val;
                ++i;
            }
        }
    }
};


class mergeSortSolution {
public:
    vector<int> sortArray(vector<int>& nums) {
        mergeSort(nums, 0, nums.size() - 1);
        return nums;
    }
    
    void mergeSort(vector<int> &arr, int left, int right) {
        if (left >= right) {
            return;
        }
        
        int mid = (left + right) / 2;
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
        
        merge(arr, left, mid, right);
    }
    
    void merge(vector<int> &arr, int left, int mid, int right) {
        int start1 = left;
        int start2 = mid + 1;
        int n1 = mid - left + 1;
        int n2 = right - mid;
        
        vector<int> v1(n1);
        vector<int> v2(n2);
        
        for (int i = 0; i < n1; i++) {
            v1[i] = arr[start1 + i];
        }
        for (int i = 0; i < n2; i++) {
            v2[i] = arr[start2 + i];
        }

        int i = 0, j = 0, k = left;
        while (i < n1 && j < n2) {
            if (v1[i] <= v2[j]) {
                arr[k] = v1[i];
                ++i;
            } 
            else {
                arr[k] = v2[j];
                ++j;
            }
            ++k;
        }

        while (i < n1) {
            arr[k] = v1[i];
            ++i;
            ++k;
        }
        while (j < n2) {
            arr[k] = v2[j];
            ++j;
            ++k;
        }
    }
};


class quickSortSolution {
public:
    vector<int> sortArray(vector<int>& nums) {
        quickSort(nums,0,nums.size()-1);
        return nums;
    }
    
    void quickSort(vector<int> &nums,int low,int high){
        if(low<high){
            int pi=partition(nums,low,high);
            quickSort(nums,low,pi-1);
            quickSort(nums,pi+1,high);
        }
    }
    
    int partition(vector<int> &nums,int low,int high){
        int pivot=nums[high];
        //Index of smaller element
        int i=low-1;
        
        //pushing all numbers lesser than pivot on one side
        for(int j=low;j<=high;++j){
            if(nums[j]<pivot){
                ++i;
                swap(nums[i],nums[j]);
            }
        }
        swap(nums[i+1],nums[high]);
        return i+1;
    }
};