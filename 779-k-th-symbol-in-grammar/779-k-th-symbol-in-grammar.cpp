class Solution {
public:
    //first half of nth raw is same as n-1th row and second hlaf will be ! of n-1the row
    //if k<=mid find in the prev row or else find ! of the element k-mid in the prev row
    int kthGrammar(int n, int k) {
        if(n==1) return 0;
        
        if(k<=pow(2,n-2)){
            return kthGrammar(n-1,k);
        }
        else{
            return !kthGrammar(n-1,k-pow(2,n-2));
        }
    }
};