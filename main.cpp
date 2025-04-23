#include "queue/queue.hpp"
#include <iostream>

int main() {
    Queue<int> list;

    std::cout << "Size: " << list.getSize() << std::endl;

    list.enqueue(1);
    list.enqueue(2);
    list.enqueue(3);
    list.enqueue(4);
    list.enqueue(5);

    std::cout << "Size: " << list.getSize() << std::endl;
    std::cout << "First: " << list.peek() << std::endl;

    list.dequeue();

    std::cout << "Size: " << list.getSize() << std::endl;

    list.enqueue(23);

    list.enqueue(8);

    list.enqueue(7);

    list.enqueue(-2);

    std::cout << "Size: " << list.getSize() << std::endl;

    list.dequeue();
    list.dequeue();

    std::cout << "Size: " << list.getSize() << std::endl;
    std::cout << "First: " << list.peek() << std::endl;
    

}

