class Solution:
    def reverseWords(self, s: str) -> str:
        a=s.split()
        ans=""
        l=len(a)
        i=l-1
        while i>=0:
            ans+=a[i]+" "
            i-=1
        return ans[:-1]