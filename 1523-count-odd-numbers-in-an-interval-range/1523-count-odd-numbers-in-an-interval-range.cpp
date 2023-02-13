class Solution {
public:
    int countOdds(int low, int high) {
        int size=high-low+1;
        
        //range can contain odd number of elements only if it starts and end with same parity number
        if(!(size&1)) return size/2;
        else return size/2 + high%2;
    }
};