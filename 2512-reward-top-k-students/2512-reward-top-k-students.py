
class Solution:
    def topStudents(self, positive_feedback: List[str], negative_feedback: List[str], report: List[str], student_id: List[int], k: int) -> List[int]:        
        p={}
        n={}
        for f in positive_feedback:
            p[f]=1
        for f in negative_feedback:
            n[f]=1
        
        ans=[]
        for i in range(len(report)):
            points=0
            words=report[i].split(" ")
            for word in words:
                if p.get(word)!=None:
                    points+=3
                elif n.get(word)!=None:
                    points-=1
            
            ans.append([points,student_id[i]])
        
        ans=sorted(ans,key=lambda x:(-x[0],x[1]))
        res=[]
        for i in range(k):
            res.append(ans[i][1])
            
        return res
        
        