#include "stack/stack.hpp"
#include <iostream>

int main() {
    Stack<int> list;

    std::cout << "Size: " << list.getSize() << std::endl;

    list.push(1);
    list.push(2);
    list.push(3);
    list.push(4);
    list.push(5);

    std::cout << "Size: " << list.getSize() << std::endl;
    std::cout << "Tail: " << list.peek() << std::endl;

    list.pop();

    std::cout << "Size: " << list.getSize() << std::endl;

    list.push(23);

    list.push(8);

    list.push(7);

    list.push(-2);

    std::cout << "Size: " << list.getSize() << std::endl;

}

