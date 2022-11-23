/** 
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is higher than the picked number
 *			      1 if num is lower than the picked number
 *               otherwise return 0
 * int guess(int num);
 */

class Solution {
public:
    int guessNumber(int n) {
        int low=0;
        int high=n;
        int mid=high-((high-low)>>1);
        while(guess(mid)){
            if(guess(mid)==-1){
                high=mid-1;
            }
            else{
                low=mid+1;
            }
            mid=high-((high-low)>>1);
        }

        return mid;
    }
};