#include <iostream>
#include "stack/stack.h"

void Multipliers(int n, MyStack<int>& stack) {
    int divisor = 2;
    while (n > 1) {
        while (n % divisor == 0) {
            stack.push(divisor);
            n /= divisor;
        }
        divisor++;
    }
}

int main() {
    MyStack<int> stack;

    std::cout << "Введите целое положительное число: ";
    int number = 3960;
    std::cin >> number;

    Multipliers(number, stack);

    std::cout << number << "= ";
    MyStack<int> invertStack;

    while (!stack.empty()) {
        int factor = stack.top_inf();
        std::cout << factor;
        invertStack.push(factor);
        stack.pop();
        std::cout << ((stack.empty()) ? "\n" : " * ");
    }

    std::cout << number << "= ";
    while (!invertStack.empty()) {
        std::cout << invertStack.top_inf();
        invertStack.pop();
        std::cout << ((invertStack.empty()) ? "\n" : " * ");
    }

    MyStack<char> charStack;
    charStack.push('A');
    charStack.push('B');
    charStack.push('C');

    std::cout << "char stack: " << charStack;
    MyStack<char> charStack1 = charStack;

    std::cout << "char stack(1): " << charStack1;

    charStack.push('D');
    charStack.push('E');
    charStack1 = charStack;

    std::cout << "char stack=: " << charStack;

    return 0;
}
// доп задание: новый стек с чарами, оператор присваивание стека, перегрузка копирования, перегрузка вывода стека
