#ifndef MYSTACK_H
#define MYSTACK_H

template<class INF, class FRIEND>
class ListNode {
 private:
    INF d;
    ListNode* next;
    ListNode() : next(nullptr) {}
    friend FRIEND;
};

template<class INF>
class MyStack {
    typedef class ListNode<INF, MyStack<INF>> Node;
    Node* top;

 public:
    MyStack() : top(nullptr) {}
    ~MyStack() {
        while (!empty()) {
            pop();
        }
    }

    bool empty() { return top == nullptr; }

    bool push(INF n) {
        Node* newNode = new Node();
        newNode->d = n;
        newNode->next = top;
        top = newNode;
        return true;
    }

    bool pop() {
        if (empty())
            return false;
        Node* temp = top;
        top = top->next;
        delete temp;
        return true;
    }

    INF top_inf() { return top->d; }
};

void Multipliers(int n, MyStack<int>& stack);
#endif  // MYSTACK_H
