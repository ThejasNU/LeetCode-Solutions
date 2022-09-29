class Solution:
    def sumPrefixScores(self, words: List[str]) -> List[int]:
        if len(words)==0:
            return words
        
        m=dict()
        w=[]
        
        for word in words:
            temp=[]
            for i in range(len(word)):
                req=word[:i+1]
                temp.append(req)
                if req not in m.keys():
                    m[req]=1
                else:
                    m[req]+=1
            w.append(temp)
        
        res=[]
        for vec in w:
            sum=0
            for j in vec:
                sum+=m[j]
            res.append(sum)
        return res
            
        