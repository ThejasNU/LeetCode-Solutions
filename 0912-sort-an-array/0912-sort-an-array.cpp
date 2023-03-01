class Solution {
    // Function to merge two sub-arrays in sorted order.
    void merge(vector<int> &arr, int left, int mid, int right, vector<int> &tempArr) {
        // Calculate the start and sizes of two halves.
        int start1 = left;
        int start2 = mid + 1;
        int n1 = mid - left + 1;
        int n2 = right - mid;
        
        // Copy elements of both halves into a temporary array.
        for (int i = 0; i < n1; i++) {
            tempArr[start1 + i] = arr[start1 + i];
        }
        for (int i = 0; i < n2; i++) {
            tempArr[start2 + i] = arr[start2 + i];
        }

        // Merge the sub-arrays 'in tempArray' back into the original array 'arr' in sorted order.
        int i = 0, j = 0, k = left;
        while (i < n1 && j < n2) {
            if (tempArr[start1 + i] <= tempArr[start2 + j]) {
                arr[k] = tempArr[start1 + i];
                i += 1;
            } else {
                arr[k] = tempArr[start2 + j];
                j += 1;
            }
            k += 1;
        }

        // Copy remaining elements
        while (i < n1) {
            arr[k] = tempArr[start1 + i];
            i += 1;
            k += 1;
        }
        while (j < n2) {
            arr[k] = tempArr[start2 + j];
            j += 1;
            k += 1;
        }
    }

    // Recursive function to sort an array using merge sort
    void mergeSort(vector<int> &arr, int left, int right, vector<int> &tempArr) {
        if (left >= right) {
            return;
        }
        int mid = (left + right) / 2;
        // Sort first and second halves recursively.
        mergeSort(arr, left, mid, tempArr);
        mergeSort(arr, mid + 1, right, tempArr);
        // Merge the sorted halves.
        merge(arr, left, mid, right, tempArr);
    }

public:
    vector<int> sortArray(vector<int>& nums) {
        vector<int> temporaryArray(nums.size());
        mergeSort(nums, 0, nums.size() - 1, temporaryArray);
        return nums;
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