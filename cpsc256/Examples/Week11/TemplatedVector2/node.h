#include<iostream>
using namespace std;

template<typename T>
class Node{
private:
    T data;
    Node<T>* next;
    template<typename U>friend class LinkedList;
public:
    Node(){
        this->next = NULL;
    }
};