/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.cc to edit this template
 */

#include "IntNode.h"

template<typename TheType>
IntNode<TheType>::IntNode(TheType dataValue) {
      //cout << "In IntNode constructor (" << dataValue << "," << next << ")" << endl;
      data = dataValue;
      next = nullptr;
}

template<typename TheType>
IntNode<TheType>::~IntNode() {
      //cout << "In IntNode destructor (";
      //cout << data << "," << next << ")" << endl;
}

template<typename TheType>
TheType IntNode<TheType>::GetData() const {
    return data;
}

template<typename TheType>
IntNode<TheType>* IntNode<TheType>::GetNext() const {
    return next;
}

template<typename TheType>
void IntNode<TheType>::SetData(TheType dataValue) {
    this->data = dataValue;
}

template<typename TheType>
void IntNode<TheType>::SetNext(IntNode* nextPtr) {
    this->next = nextPtr;
}

template<typename TheType>
void IntNode<TheType>::PrintNodeData() {
    cout << "Node: "  << &(this->data) << " value = " << this->data << endl;
    cout << "---------------------" << endl;
}
