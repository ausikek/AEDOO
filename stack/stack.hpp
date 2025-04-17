#include "../linked-list/linked-list.hpp"

template<typename T>
class Stack {
    private:
        LinkedList<T>* list;

    public:
        Stack() {
            list = new LinkedList<T>();
        }

        Stack(LinkedList<T>* list) {
            this->list = list;
        }

        ~Stack() {
            delete list;
        }

        void push(T item);
        void pop();
        int getSize();
        bool isEmpty();
        T peek();
};

template<typename T>
void Stack<T>::push(T item) {
    list->add(item);
}

template<typename T>
void Stack<T>::pop() {
    list->pop();
}

template<typename T>
T Stack<T>::peek() {
    return list->getTail();
}

template<typename T>
int Stack<T>::getSize() {
    return list->getSize();
}

template<typename T>
bool Stack<T>::isEmpty() {
    return list->getSize() == 0;
}