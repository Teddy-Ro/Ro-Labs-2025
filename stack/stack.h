#ifndef MYSTACK_H
#define MYSTACK_H
#include <algorithm>
#include <iostream>

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

    MyStack(const MyStack& copy) : top(nullptr) {
        MyStack temp;
        Node* current = copy.top;
        while (current != nullptr) {
            temp.push(current->d);
            current = current->next;
        }

        while (!temp.empty()) {
            push(temp.top_inf());
            temp.pop();
        }
    }

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

    MyStack& operator=(const MyStack& other) {
        if (this != &other) {
            MyStack temp(other);
            std::swap(top, temp.top);
        }
        return *this;
    }

    friend std::ostream& operator<<(std::ostream& out, const MyStack& stack) {
        Node* current = stack.top;
        out << "(";

        while (current != nullptr) {
            out << current->d;
            current = current->next;
            if (current != nullptr) {
                out << "; ";
            } else {
                out << ")\n";
            }
        }
        return out;
    }
};

#endif  // MYSTACK_H
