#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <iostream>
#include <fstream>    
#include "node.h"
#include "zombie.h"

using namespace std;

template<typename T>
class LinkedList {
public:
    LinkedList();
    ~LinkedList();

    void AddToFront(T data);
    void AddToEnd(T data);
    bool AddAtIndex(T data, int index);

    T RemoveFromFront();
    T RemoveFromEnd();
    void RemoveTheFirst(T data);
    void RemoveAllOf(T data);

    bool ElementExists(T data);
    Node<T> * Find(T data);
    int IndexOf(T data);

    T RetrieveFront();
    T RetrieveEnd();
    T Retrieve(int index);

    void PrintList();

    void Empty();

    int Length();

private:
    Node<T> * head, * tail;
    int count;
};

/**
 * Constructor
 */
template<typename T>
LinkedList<T>::LinkedList() {
    head = tail = nullptr;
    count = 0;
}

/**
 * Destructor
 */
template<typename T>
LinkedList<T>::~LinkedList() {
    Empty();
}

/**
 * Create a node containing T data and add it to the front of the list
 */
template<typename T>
void LinkedList<T>::AddToFront(T data) {
    Node<T> * newNode = new Node<T>(data);
    if (head == nullptr) { // if the list is empty
        // set this node as the head and the tail
        head = tail = newNode;
    } else { // otherwise
        // prepend this node to the head
        newNode->SetNext(head);
        head = newNode;
    }
    // increase size
    count++;
}

/**
 * Create a node containing T data and add it to the end of the list
 */
template<typename T>
void LinkedList<T>::AddToEnd(T data) {
    Node<T> * newNode = new Node<T>(data);
    if (tail == nullptr) { // if the list is empty
        // set this node as the head and the tail
        head = tail = newNode;
    } else { // otherwise
        // append this node to the tail
        tail->SetNext(newNode);
        tail = newNode;
    }
    // increase size
    count++;
}

/**
 * Create a node containing T data and add it to the list at index.
 * The new node containing the data will be the #index node in the list.
 * Return boolean for success or failure.
 */
template<typename T>
bool LinkedList<T>::AddAtIndex(T data, int index) {
    if (index < 0 || index > count) // not a valid index
        return false;
    if (index == 0) { // prepend
        AddToFront(data);
        return true;
    } else if (index == count) { // append
        AddToEnd(data);
        return true;
    } else { // insert
        // find place to insert
        int i = 0;
        Node<T> * prevNode = nullptr;
        Node<T> * currNode = head;
        while (i < index) {
            prevNode = currNode;
            currNode = currNode->GetNext();
            i++;
        }
        // create a new node
        Node<T> * newNode = new Node<T>(data);
        // insert between prevNode and currNode
        prevNode->SetNext(newNode);
        newNode->SetNext(currNode);
        // increase size
        count++;
        return true;
    }
}

/**
 * Delete first item and return its contents
 */
template<typename T>
T LinkedList<T>::RemoveFromFront() {
    if (count == 0) { // no items
        T t;
        return t;
    } else if (count == 1) { // only 1 item
        // save data
        T data = head->GetData();
        // empty list
        Empty();
        // return saved data
        return data;
    } else { // multiple items
        // save data
        T data = head->GetData();
        // get new head
        Node<T> * newHead = head->GetNext();
        // remove head
        delete head;
        // set new head
        head = newHead;
        // decrease count
        count--;
        // return saved data
        return data;
    }
}

/**
 * Delete first item and return its contents
 */
template<typename T>
T LinkedList<T>::RemoveFromEnd() {
    if (count == 0) { // no items
        T t;
        return t;
    } else if (count == 1) { // only 1 item
        // save data
        T data = tail->GetData();
        // empty list
        Empty();
        // return saved data
        return data;
    } else { // multiple items
        // save data
        T data = tail->GetData();
        // get new tail
        Node<T> * newTail = head;
        while (newTail->GetNext() != tail)
            newTail = newTail->GetNext();
        // remove tail
        delete tail;
        // set new head
        tail = newTail;
        tail->SetNext(nullptr);
        // decrease count
        count--;
        // return saved data
        return data;
    }
}

/**
 * Find first instance of T data and remove it
 */
template<typename T>
void LinkedList<T>::RemoveTheFirst(T data) {
    if (count == 0) // list is empty
        return;
    // search one by one from head
    Node<T> * prevNode = nullptr;
    Node<T> * currNode = head;
    while (currNode != nullptr) {
        if (currNode->GetData() == data) { // match found
            if (currNode == head) // special case - head
                RemoveFromFront();
            else if (currNode == tail) // special case - tail
                RemoveFromEnd();
            else { // otherwise
                prevNode->SetNext(currNode->GetNext());
                count--;
                delete currNode;
            }
            return;
        }
        prevNode = currNode;
        currNode = currNode->GetNext();
    }
}

/**
 * Find each instance of T data and remove it
 */
template<typename T>
void LinkedList<T>::RemoveAllOf(T data) {
    if (count == 0) // list is empty
        return;
    // search one by one from head
    Node<T> * prevNode = nullptr;
    Node<T> * currNode = head;
    while (currNode != nullptr) {
        if (currNode->GetData() == data) { // match found
            if (currNode == head) { // special case - head
                RemoveFromFront();
                currNode = head;
            } else if (currNode == tail) { // special case - tail
                RemoveFromEnd();
                currNode = tail;
            } else { // otherwise
                Node<T> * nextNode = currNode->GetNext();
                prevNode->SetNext(nextNode);
                count--;
                delete currNode;
                currNode = nextNode;
            }
            continue;
        }
        prevNode = currNode;
        currNode = currNode->GetNext();
    }
}

/**
 * a T/F if element exists in list
 */
template<typename T>
bool LinkedList<T>::ElementExists(T data) {
    // Search one by one
    Node<T> * currNode = head;
    while (currNode != nullptr) {
        if (currNode->GetData() == data)
            return true;
        currNode = currNode->GetNext();
    }
    // not found
    return false;
}

/**
 * Look for data in the list, return a pointer to its node
 */
template<typename T>
Node<T> * LinkedList<T>::Find(T data) {
    // Search one by one
    Node<T> * currNode = head;
    while (currNode != nullptr) {
        if (currNode->GetData() == data)
            return currNode;
        currNode = currNode->GetNext();
    }
    // not found
    return nullptr;
}

/**
 * Returns an index of the item in the list (zero-based)
 */
template<typename T>
int LinkedList<T>::IndexOf(T data) {
    // Search one by one
    Node<T> * currNode = head;
    int index = 0;
    while (currNode != nullptr) {
        if (currNode->GetData() == data)
            return index;
        currNode = currNode->GetNext();
        index++;
    }
    // not found
    return -1;
}

/**
 * Returns the data contained in the first node, does not delete it
 */
template<typename T>
T LinkedList<T>::RetrieveFront() {
    if (count == 0) // list is empty
        return nullptr;
    else
        return head->GetData();
}

/**
 * Returns the data contained in the last node, does not delete it
 */
template<typename T>
T LinkedList<T>::RetrieveEnd() {
    if (count == 0) // list is empty
        return nullptr;
    else
        return tail->GetData();
}

/**
 * Returns the data contained in node # index, does not delete
 */
template<typename T>
T LinkedList<T>::Retrieve(int index) {
    if (index >= count) // not a valid index
        return nullptr;
    // find index node
    Node<T> * currNode = head;
    while (index > 0) {
        currNode = currNode->GetNext();
        index--;
    }
    // return data
    return currNode->GetData();
}

/**
 * Loop through each node and print the contents of the Node
 */
template<typename T>
void LinkedList<T>::PrintList() {
    cout << "Size: " << count;
    // if list is empty
    if (count == 0) {
        cout << endl;
        return;
    }
    // otherwise, print every node
    cout << " ::";
    Node<T> * currNode = head;
    while (currNode != nullptr) {
        cout << currNode->GetData();
        currNode = currNode->GetNext();
    }
    cout << endl;
}

/**
 * Empty out the list, delete everything
 */
template<typename T>
void LinkedList<T>::Empty() {
    // delete nodes one by one
    Node<T> * currNode = head;
    while (currNode != nullptr) {
        currNode = currNode->GetNext();
        delete head;
        head = currNode;
    }
    // reset everything
    head = tail = nullptr;
    count = 0;
}

/**
 * How many elements are in the list
 */
template<typename T>
int LinkedList<T>::Length() {
    return count;
}
#endif // LINKEDLIST_H
