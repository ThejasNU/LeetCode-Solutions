class Node{
public:
    int key;
    int value;
    Node* next;
    Node* prev;
    Node(int _key,int _value){
        key=_key;
        value=_value;
    }
};

class LRUCache {
public:
    int cap;
    Node* head;
    Node* tail;
    unordered_map<int,Node*> m;

    LRUCache(int capacity) {
        cap=capacity;
        head=new Node(-1,-1);
        tail=new Node(-1,-1);
        head->next=tail;
        tail->prev=head;
    }
    
    int get(int key) {
        if(m.find(key)!=m.end()){
            Node* foundNode=m[key];
            int key=foundNode->key;
            int value=foundNode->value;
            deleteNode(foundNode);
            addNode(new Node(key,value));
            return value;
        }
        else return -1;
    }
    
    void put(int key, int value) {
        if(m.find(key)!=m.end()){
            deleteNode(m[key]);
        }
        if(m.size()==cap){
            deleteNode(tail->prev);
        }
        addNode(new Node(key,value));
    }

    //helpers
    void addNode(Node* node){
        Node* nextNode=head->next;
        nextNode->prev=node;
        head->next=node;
        node->prev=head;
        node->next=nextNode;
        m[node->key]=node;
    }

    void deleteNode(Node* node){
        Node* nextNode=node->next;
        Node* prevNode=node->prev;
        prevNode->next=nextNode;
        nextNode->prev=prevNode;
        m.erase(node->key);
        delete node;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */