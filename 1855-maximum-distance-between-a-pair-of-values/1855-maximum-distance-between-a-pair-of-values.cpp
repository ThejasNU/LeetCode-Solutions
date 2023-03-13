class Solution {
public:
    int maxDistance(vector<int>& nums1, vector<int>& nums2) {
        int n1=nums1.size(),n2=nums2.size();
        int maxDist=0;
        int p1=0,p2=0;
        while(p1<n1 && p2<n2){
            if(nums1[p1]>nums2[p2]) ++p1;
            else{
                maxDist=max(maxDist,p2-p1);
                ++p2;
            }
        }
        return maxDist;
    }
};

class binarySearchSolution {
public:
    int maxDistance(vector<int>& nums1, vector<int>& nums2) {
        int n1=nums1.size(),n2=nums2.size();
        int maxDist=0;
        
        int i=0;
        while(i<n1){
            int k=nums2.rend()-lower_bound(nums2.rbegin(),nums2.rend(),nums1[i]);
            if(k>0) maxDist=max(maxDist,k-i-1);
            while(i<n1-1 && nums1[i]==nums1[i+1]) ++i;
            ++i;
        }
        return maxDist;
    }
};