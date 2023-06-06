class Solution {
public:
    bool canMakeArithmeticProgression(vector<int>& arr) {
        int n=arr.size();
        int maxVal=*max_element(arr.begin(), arr.end());
        int minVal=*min_element(arr.begin(), arr.end());
        if((maxVal-minVal)%(n-1)!=0) return false;
        int dif=(maxVal-minVal)/(n-1);
        int i=0;
        while(i<n){
            if(arr[i]==minVal+i*dif){
                ++i;
            }
            else if((arr[i]-minVal)%dif!=0){
                return false;
            }
            else{
                int ind=(arr[i]-minVal)/dif;
                //duplicate elements
                if(arr[i]==arr[ind]) return false;

                swap(arr[i],arr[ind]);
            }
        }
        return true;
    }
};

class sortingSolution {
public:
    bool canMakeArithmeticProgression(vector<int>& arr) {
        int n=arr.size();
        sort(arr.begin(),arr.end());
        int dif=arr[1]-arr[0];
        for(int i=2;i<n;++i){
            if(arr[i]-arr[i-1]!=dif) return false;
        }
        return true;
    }
};