/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/main.cc to edit this template
 */

/* 
 * File:   main.cpp
 * Author: 00465510
 *
 * Created on November 6, 2021, 7:32 PM
 */

#include <cstdlib>
#include "LinkedList.h"

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    
   // Create a linked list - this will just create a single node, the head,
   // with data = 0
   LinkedList* list = new LinkedList;
   
   // Prepend several nodes to list
   // After this loop, there will be 10 nodes in the list
   // The head node will be the last node added (i.e., data = 100)
   // The last node added will be the first node in the list (i.e., data = 10),
   // and more importantly, this last node will have a null pointer for its next
   // pointer, indicating that it is the last node in the list.

   for (int i = 1; i <= 10; ++i) {
      list->Prepend(i * 10);
      //cout << "Head now at: " << list->GetHead() << endl;
   }

    // Print the list
    list->PrintList();

    // Now, insert a new object just after the head node of the list
    list->Insert(999, 1);

    // Remove the 5th node in the list
    list->Remove(5);

    // Add a new node to the end of the list
    list->Append(1000);

    // Print the list
    list->PrintList();

   // Free the linked list.
   // The LinkedList class destructor frees each node, starting with the head node.
   // The destructor will call the destructor for each node, which will free the
   // next node, and so on, until the last node is freed.
   delete list;

   return 0;
}

