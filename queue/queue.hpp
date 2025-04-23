#include "../linked-list/linked-list.hpp"

template <typename T>
class Queue {
    private:
        LinkedList<T>* list;
    public:
        Queue() {
            list = new LinkedList<T>();
        }

        Queue(LinkedList<T>* list) {
            this->list = list;
        }

        ~Queue() {
            delete list;
        }

        void enqueue(T item);
        void dequeue();
        int getSize();
        bool isEmpty();
        T peek();
};

template <typename T>
void Queue<T>::enqueue(T item) {
    list->add(item);
}

template <typename T>
void Queue<T>::dequeue() {
    list->remove(0);
}

template <typename T>
T Queue<T>::peek() {
    return list->getHead();
}

template <typename T>
int Queue<T>::getSize() {
    return list->getSize();
}

template <typename T>
bool Queue<T>::isEmpty() {
    return list->getSize() == 0;
}
