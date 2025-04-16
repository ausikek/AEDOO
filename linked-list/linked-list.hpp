#define LINKEDLIST_HPP


#include <iostream>

template <typename T>
class Node {
    public:
        T data;
        Node* next;

        Node(T value) {
            data = value;
            next = nullptr;
        }
};

template <typename T>
class LinkedList {
    private:
        Node<T>* head;
        Node<T>* tail;
        int size;
        bool checkBounds(int index);

    public:

        LinkedList() {
            head = nullptr;
            tail = nullptr;
            size = 0;
        }

        LinkedList(T value) {
            head = new Node<T>(value);
            tail = head;
        }

        ~LinkedList() {
            Node<T>* current = head;
            while (current != nullptr) {
                Node<T>* nextNode = current-> next;
                delete current;
                current = nextNode;
            }
        }

        T getHead();
        T getTail();
        T peek(int index);
        T operator[](int index);
        int getSize();
        void add(T value);
        void pop();
        void invert();
        void print();
        void sort();
        void insert(int index, T value);
        void remove(int index);
        void overwrite(int index, T value);
};

/*Check if the index passed is valid*/
template <typename T>
bool LinkedList<T>::checkBounds(int index) {
    return index >= 0 && index < size;
}

/*Print the list*/
template <typename T>
T LinkedList<T>::getHead() {
    if (size == 0) {
        std::cout << "List is empty." << std::endl;
        return T();
    }

    return head->data;
}

/*Get the last element of the list*/
template <typename T>
T LinkedList<T>::getTail() {
    if (size == 0) {
        std::cout << "List is empty." << std::endl;
        return T();
    }

    return tail->data;
}

/*Get the value at a specific index*/
template <typename T>
T LinkedList<T>::peek(int index) {
    if (size == 0) {
        std::cout << "List is empty." << std::endl;
        return T();
    }

    if (!checkBounds(index)) {
        std::cout << "Index out of bounds." << std::endl;
        return T();
    }

    Node<T>* current = head;
    for (int i = 0; i < index; i++) {
        current = current->next;
    }
    return current->data;
}

/*Overload the [] operator to access elements in the list*/
template <typename T>
T LinkedList<T>::operator[](int index) {
    return peek(index);
}

/*Get the size of the list*/
template <typename T>
int LinkedList<T>::getSize() {
    return size;
}

/*Add item T to the end of the list*/
template <typename T>
void LinkedList<T>::add(T value) {
    Node<T>* newNode = new Node<T>(value);

    if (head == nullptr) {
        head = newNode;
        tail = newNode;
    } else {
        tail->next = newNode;
        tail = newNode;
    }

    size++;

    print();
}

/*Remove item T from the end of the list*/
template <typename T>
void LinkedList<T>::pop() {
    if (size == 0) {
        std::cout << "List is empty." << std::endl;
        return;
    }

    Node<T>* current = head;
    Node<T>* previous = nullptr;

    while (current -> next != nullptr) {
        previous = current;
        current = current->next;
    }

    if (previous != nullptr) {
        tail = previous;
        tail->next = nullptr;
    } else {
        head = nullptr;
        tail = nullptr;
    }

    delete current;

    size--;

    if (size < 0) {
        size = 0;
    }

    print();
}

/*Invert the list*/
template <typename T>
void LinkedList<T>::invert() {
    Node<T>* current = head;
    Node<T>* previous = nullptr;
    Node<T>* nextNode = nullptr;

    while (current != nullptr) {
        nextNode = current->next;
        current->next = previous;
        previous = current;
        current = nextNode;
    }

    tail = head;
    head = previous;

    print();
}

/*Print the list*/
template <typename T>
void LinkedList<T>::print() {
    Node<T>* current = head;

    while (current != nullptr) {
        std::cout << current->data << " -> ";
        current = current->next;
    }

    std::cout << "nullptr" << std::endl;
}

/*Sort the list using quicksort*/
/*TODO*/
template <typename T>
void LinkedList<T>::sort() {}

/*Insert item T at a specific index*/
template <typename T>
void LinkedList<T>::insert(int index, T value) {
    if (!checkBounds(index)) {
        std::cout << "Index out of bounds." << std::endl;
        return;
    }

    Node<T>* newNode = new Node<T>(value);

    if (index == 0) {
        newNode -> next = head;
        head = newNode;

        if (tail == nullptr) {
            tail = newNode;
        }

    } else {
        Node<T>* current = head;
        for (int i = 0; i < index - 1; i++) {
            current = current->next;
        }

        newNode->next = current->next;
        current->next = newNode;

        if (newNode->next == nullptr) {
            tail = newNode;
        }
    }

    size++;

    print();
}

/*Remove item T at a specific index*/
template <typename T>
void LinkedList<T>::remove(int index) {
    if (size == 0) {
        std::cout << "List is empty." << std::endl;
        return;
    }

    if (!checkBounds(index)) {
        std::cout << "Index out of bounds." << std::endl;
        return;
    }

    Node<T>* current = head;
    Node<T>* previous = nullptr;

    for (int i = 0; i < index; i++) {
        previous = current;
        current = current->next;
    }

    if (previous == nullptr) {
        head = current->next;
    } else {
        previous->next = current->next;
    }

    if (current == tail) {
        tail = previous;
    }

    delete current;

    size--;

    if (size < 0) {
        size = 0;
    }

    print();
}

/*Overwrite item T at a specific index*/
template <typename T>
void LinkedList<T>::overwrite(int index, T value) {
    if (size == 0) {
        std::cout << "List is empty." << std::endl;
        return;
    }

    if (!checkBounds(index)) {
        std::cout << "Index out of bounds." << std::endl;
        return;
    }

    Node<T>* current = head;

    for (int i = 0; i < index; i++) {
        current = current->next;
    }

    current->data = value;

    print();
}