/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.h to edit this template
 */

/* 
 * File:   IntNode.h
 * Author: 00465510
 *
 * Created on November 6, 2021, 7:32 PM
 */

#ifndef INTNODE_H
#define INTNODE_H

#include <iostream>
using namespace std;

template<typename TheType>
class IntNode {
private:
    TheType data;
    IntNode* next;
    template<typename U>friend class LinkedList;
public:
   IntNode(TheType dataValue) {
        this->data = dataValue;
        this->next = NULL;
   }

   ~IntNode() {
       //cout << "Destructor called for " << data << endl;
   }

   TheType GetData() const {
       return data;
   }

   IntNode* GetNext() const {
       return next;
   }
   
   void SetData(TheType dataValue) {
       data = dataValue;
   }

   void SetNext(IntNode* nextPtr) {
       next = nextPtr;
   }

   void PrintNodeData() {
       cout << "Node: "  << &(this->data) << " value = " << this->data << endl;
       cout << "---------------------" << endl;
   }
};

#endif /* INTNODE_H */

