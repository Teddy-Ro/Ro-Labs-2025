#ifndef MYSTACK_H
#define MYSTACK_H

#include <algorithm>

template<class INF>
class MyStack {
private:
    struct Node {
        INF d;
        Node* next;
        Node(INF data) : d(data), next(nullptr) {}
    };

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
            push(temp.topInf());
            temp.pop();
        }
    }

    ~MyStack() {
        while (!empty()) {
            pop();
        }
    }

    bool empty() const { return top == nullptr; }

    void push(INF n) {
        Node* newNode = new Node(n);
        newNode->next = top;
        top = newNode;
    }

    void pop() {
        if (!empty()) {
            Node* temp = top;
            top = top->next;
            delete temp;
        }
    }

    INF topInf() const {
        return top->d;
    }

    MyStack& operator=(const MyStack& other) {
        if (this != &other) {
            MyStack temp(other);
            std::swap(top, temp.top);
        }
        return *this;
    }
};

#endif // MYSTACK_H
