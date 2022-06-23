I'm getting TLE in this code for the test case
```
[1,2,3]
2000000000
```
​
```
class Solution {
public:
ListNode* rotateRight(ListNode* head, int k) {
if(head==nullptr || head->next==nullptr || k==0) return head;
ListNode* start=new ListNode();
start->next=head;
ListNode* fast=start;
ListNode* slow=start;
int count=0;
while(count<k){
fast=(fast->next?fast->next:head); //when rotations are greater than number of elements
count++;
}
//edge case: when number of rotations is equal to number of nodes
if(fast->next==nullptr) return head;
while(fast->next!=nullptr){
fast=fast->next;
slow=slow->next;
}
fast->next=head;
head=slow->next;
slow->next=nullptr;
return head;
}
};
```