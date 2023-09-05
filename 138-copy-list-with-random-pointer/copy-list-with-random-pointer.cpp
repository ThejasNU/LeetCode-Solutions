/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(head==NULL) return head;
        Node* cur=head;
        while(cur!=NULL){
            Node* temp= new Node(cur->val);
            temp->next=cur->next;
            cur->next=temp;
            cur=cur->next->next;
        }
        
        cur=head;
        while(cur!=NULL){
            cur->next->random=cur->random?cur->random->next:NULL;
            cur=cur->next->next;
        }

        cur=head;
        Node* front=head;
        Node* newHead=new Node(0);
        newHead->next=cur->next;
        Node* newCur=newHead->next;
        
        while(cur!=NULL){
            front=cur->next->next;
            cur->next=front;
            newCur->next=front?front->next:NULL;
            
            cur=cur->next;
            newCur=newCur->next;
        }

        return newHead->next;
    }
};