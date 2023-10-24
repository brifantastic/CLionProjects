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

class LinkedList {
public:
    
   LinkedList(); // default constructor
   ~LinkedList();  // destructor frees up entire linked list
   
   void Prepend(int dataValue); // add a new node to the front of the list
   
   IntNode* GetHead() const; // return the head pointer
   void SetHead(IntNode* headPtr); // set the head pointer
   
private:
   IntNode* head; // pointer to the first node in the list
   
};

#endif /* LINKEDLIST_H */

