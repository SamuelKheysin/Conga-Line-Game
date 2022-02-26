#ifndef NODE_H
#define NODE_H

template<typename T>   
class Node {
public:
    Node(T t);
    ~Node();

    void SetData(T t);
    T GetData();

    void SetNext(Node<T> * next);
    Node<T> * GetNext();

private:
    T data;
    Node<T> * next;
};

template<typename T>
Node<T>::Node(T t) {
    this->data = t;
    this->next = nullptr;
}

template<typename T>
Node<T>::~Node() {
    this->next = nullptr;
}

template<typename T>
void Node<T>::SetData(T t) {
    this->data = t;
}

template<typename T>
T Node<T>::GetData() {
    return this->data;
}

template<typename T>
void Node<T>::SetNext(Node<T> * next) {
    this->next = next;
}

template<typename T>
Node<T> * Node<T>::GetNext() {
    return this->next;
}

#endif // NODE_H
