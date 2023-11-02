/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.h to edit this template
 */

/* 
 * File:   LinkedList.h
 * Author: 00465510
 *
 * Created on November 6, 2021, 7:36 PM
 */

#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include "IntNode.h"

#include <iostream>
using namespace std;

template<typename TheType>
class LinkedList {
private:
    IntNode<TheType>* head; // pointer to the first node in the list
public:
   LinkedList() {
        head = nullptr;
   };

   ~LinkedList() {
       while (this->head != nullptr) {
           //IntNode<TheType>* next = head->GetNext();
           auto next = head->GetNext();
           delete head;
           head = next;
       }
   };  // destructor frees up entire linked list
   
   void Prepend(TheType dataValue) {
         //IntNode<TheType>* newNode = new IntNode<TheType>(dataValue);
         auto newNode = new IntNode<TheType>(dataValue);
         newNode->SetNext(head);
         head = newNode;
    }; // add a new node to the front of the list

   void Append(TheType dataValue) {
         //IntNode<TheType>* newNode = new IntNode<TheType>(dataValue);
         auto newNode = new IntNode<TheType>(dataValue);
         if (head == nullptr) {
              head = newNode;
         } else {
              IntNode<TheType>* current = head;
              while (current->GetNext() != nullptr) {
                current = current->GetNext();
              }
              current->SetNext(newNode);
         }
   }; // add a new node to the end of the list

   void Insert(TheType dataValue, int position) {
         //IntNode<TheType>* newNode = new IntNode<TheType>(dataValue);
         auto newNode = new IntNode<TheType>(dataValue);
         if (position == 0) {
              newNode->SetNext(head);
              head = newNode;
         } else {
              IntNode<TheType>* current = head;
              for (int i = 0; i < position - 1; i++) {
                current = current->GetNext();
              }
              newNode->SetNext(current->GetNext());
              current->SetNext(newNode);
         }
   }; // insert a new node at position

   void Remove(int position) {
            if (position == 0) {
                IntNode<TheType>* current = head;
                head = head->GetNext();
                delete current;
            } else {
                IntNode<TheType>* current = head;
                for (int i = 0; i < position - 1; i++) {
                    current = current->GetNext();
                }
                IntNode<TheType>* temp = current->GetNext();
                current->SetNext(temp->GetNext());
                delete temp;
            }
   }; // remove the node at position

   void PrintList() {
        //IntNode<TheType>* currObj = head;
        auto currObj = head;
        cout << "Linked List:" << endl << endl;
        while (currObj != nullptr) {
           currObj->PrintNodeData();
           currObj = currObj->GetNext();
        }

   }; // print the list

   IntNode<TheType>* GetHead() const {
         return this->head;
   }; // return the head pointer

   void SetHead(IntNode<TheType>* headPtr) {
            this->head = headPtr;
   }; // set the head pointer
   
};

#endif /* LINKEDLIST_H */

