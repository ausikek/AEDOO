#include "linked-list/linked-list.hpp"
#include <iostream>

int main() {
    LinkedList<int> list;

    list.add(1);
    list.add(2);
    list.add(3);
    list.add(4);
    list.add(5);

    std::cout << "Size: " << list.getSize() << std::endl;
    std::cout << "Head: " << list.getHead() << std::endl;
    std::cout << "Tail: " << list.getTail() << std::endl;

    list.pop();

    std::cout << "Size: " << list.getSize() << std::endl;

    list.invert();

    list.add(23);

    list.add(8);

    list.add(7);

    list.add(-2);

    std::cout << "Size: " << list.getSize() << std::endl;

    std::cout << "Item at index 4: " << list[4] << std::endl;
    std::cout << "Item at index 2: " << list.peek(2) << std::endl;

    list.remove(2);

    list.insert(2, 99);

    list.overwrite(2, 100);

    std::cout << "Size: " << list.getSize() << std::endl;
}

