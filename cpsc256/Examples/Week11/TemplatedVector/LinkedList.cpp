/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.cc to edit this template
 */

#include "LinkedList.h"

// A linked list is a collection of nodes
// Each node contains a data value and a pointer to the next node in the list
// The LinkedList class contains a pointer to the first node in the list ... that's it!
//
// The LinkedList class destructor frees up the ENTIRE linked list ... this is the
//    power of the destructor!
//
// The LinkedList Prepend method adds a new node to the front of the list.  To do this,
//    it creates a new node, sets the new node's next pointer to the current head of the
//    list, and then sets the head pointer to the new node.
//
// The only other methods we need are GetHead and SetHead.  These are used to access
//    and modify the head pointer.

template<typename TheType>
LinkedList<TheType>::LinkedList() {
   head = nullptr;
   //cout << "In LinkedList constructor: " << head << endl;
}

template<typename TheType>
LinkedList<TheType>::~LinkedList() {
   //cout << "In LinkedList destructor: " << endl;
   // The destructor deletes each node in the linked list

   while (this->head != nullptr) {
       //IntNode<TheType>* next = head->GetNext();
       auto next = head->GetNext();
       delete head;
       head = next;
   }
}

template<typename TheType>
void LinkedList<TheType>::Prepend(TheType dataValue) {
   //IntNode<TheType>* newNode = new IntNode<TheType>(dataValue);
   auto newNode = new IntNode<TheType>(dataValue);
   newNode->SetNext(head);
   head = newNode;
}

template<typename TheType>
IntNode<TheType>* LinkedList<TheType>::GetHead() const {
    return this->head;
}

template<typename TheType>
void LinkedList<TheType>::SetHead(IntNode<TheType>* headPtr) {
    this->head = headPtr;
}

template<typename TheType>
void LinkedList<TheType>::PrintList() {
    //IntNode<TheType>* currObj = head;
    auto currObj = head;
    cout << "Linked List:" << endl << endl;
    while (currObj != nullptr) {
       currObj->PrintNodeData();
       currObj = currObj->GetNext();
    }
}

template<typename TheType>
void LinkedList<TheType>::Append(TheType dataValue) {
    //IntNode<TheType>* newNode = new IntNode<TheType>(dataValue);
    auto newNode = new IntNode<TheType>(dataValue);
    //IntNode<TheType>* currObj = head;
    auto currObj = head;
    while (currObj->GetNext() != nullptr) {
        currObj = currObj->GetNext();
    }
    currObj->SetNext(newNode);
}

template<typename TheType>
void LinkedList<TheType>::Insert(TheType dataValue, int position) {
    //IntNode<TheType>* newNode = new IntNode<TheType>(dataValue);
    auto newNode = new IntNode<TheType>(dataValue);
    //IntNode<TheType>* currObj = head;
    auto currObj = head;
    for (int i = 0; i < position - 1; ++i) {
        currObj = currObj->GetNext();
    }
    newNode->SetNext(currObj->GetNext());
    currObj->SetNext(newNode);
}

template<typename TheType>
void LinkedList<TheType>::Remove(int position) {
    //IntNode<TheType>* currObj = head;
    auto currObj = head;
    for (int i = 0; i < position - 1; ++i) {
        currObj = currObj->GetNext();
    }
    //IntNode<TheType>* temp = currObj->GetNext();
    auto temp = currObj->GetNext();
    currObj->SetNext(temp->GetNext());
    delete temp;
}

