class Node {
public:
    int val;
    Node* next;
    Node* prev;

    Node(int val, Node* next, Node* prev) {
        this->val = val;
        this->next = next;
        this->prev = prev;
    }
};

class MyCircularDeque {
private:
    int len;
    int maxLen;
    Node* head;
    Node* tail;

public:
    MyCircularDeque(int k) {
        len = 0;
        maxLen = k;
        head = nullptr;
        tail = nullptr;
    }

    bool insertFront(int value) {
        if (isFull()) {
            return false;
        }

        if (isEmpty()) {
            head = tail = new Node(value, nullptr, nullptr);
        } else {
            Node* front = new Node(value, head, nullptr);
            head->prev = front;
            head = front;
            front = nullptr;
            delete front;
        }

        ++len;
        return true;
    }

    bool insertLast(int value) {
        if (isFull()) {
            return false;
        }

        if (isEmpty()) {
            head = tail = new Node(value, nullptr, nullptr);
        } else {
            Node* last = new Node(value, nullptr, tail);
            tail->next = last;
            tail = last;
            last = nullptr;
            delete last;
        }

        ++len;
        return true;
    }

    bool deleteFront() {
        if (isEmpty()) {
            return false;
        }

        if (len == 1) {
            Node* temp = head;
            head = tail = nullptr;
            delete temp;
        } else {
            Node* temp = head;
            head = head->next;
            head->prev = nullptr;
            delete temp;
        }

        --len;
        return true;
    }

    bool deleteLast() {
        if (isEmpty()) {
            return false;
        }

        if (len == 1) {
            Node* temp = head;
            head = tail = nullptr;
            delete temp;
        } else {
            Node* temp = tail;
            tail = tail->prev;
            tail->next = nullptr;
            delete temp;
        }

        --len;
        return true;
    }

    int getFront() {
        if (isEmpty()) {
            return -1;
        }

        return head->val;
    }

    int getRear() {
        if (isEmpty()) {
            return -1;
        }

        return tail->val;
    }

    bool isEmpty() { return len == 0; }

    bool isFull() { return len == maxLen; }
};

/**
 * Your MyCircularDeque object will be instantiated and called as such:
 * MyCircularDeque* obj = new MyCircularDeque(k);
 * bool param_1 = obj->insertFront(value);
 * bool param_2 = obj->insertLast(value);
 * bool param_3 = obj->deleteFront();
 * bool param_4 = obj->deleteLast();
 * int param_5 = obj->getFront();
 * int param_6 = obj->getRear();
 * bool param_7 = obj->isEmpty();
 * bool param_8 = obj->isFull();
 */