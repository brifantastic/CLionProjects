/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.cc to edit this template
 */

#include "LinkedList.h"
#include "IntNode.h"

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

LinkedList::LinkedList() {
   
   head = nullptr;
   cout << "In LinkedList constructor: " << head << endl;
}

LinkedList::~LinkedList() {
   cout << "In LinkedList destructor: " << endl;
    
   // The destructor deletes each node in the linked list
   while (head) {
      IntNode* next = head->GetNext();
      delete head;
      head = next;
   }
}

void LinkedList::Prepend(int dataValue) {
   IntNode* newNode = new IntNode(dataValue);
   newNode->SetNext(head);
   head = newNode;
}

IntNode* LinkedList::GetHead() const {
    return this->head;
}

void LinkedList::SetHead(IntNode* headPtr) {
    this->head = headPtr;
}

