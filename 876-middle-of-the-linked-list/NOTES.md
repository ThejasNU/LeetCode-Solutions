It can also be written as
```
ListNode* middleNode(ListNode* head) {
if(head==NULL|| head->next==NULL)
return head;
ListNode* slow=head;
ListNode* fast =head;
while(fast!=NULL&& fast->next!=NULL){
fast=fast->next->next;
slow=slow->next;
}
return slow;
}
​
```