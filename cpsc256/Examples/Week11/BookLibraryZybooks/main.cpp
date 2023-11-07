/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/main.cc to edit this template
 */

/* 
 * File:   main.cpp
 * Author: 00465510
 *
 * Created on November 11, 2021, 8:42 AM
 */

#include "BookLibary.h"

#include <fstream>
#include <iostream>
#include <string>
#include <cstdlib>
#include <chrono>

void FillLibraries(LinkedListLibrary &linkedListLibrary, VectorLibrary &vectorLibrary) {
    ifstream inputFS; // File input stream
    int linkedListOperations = 0;
    int vectorOperations = 0;

    BookNode* currNode;
    Book tempBook;

    string bookTitle;
    string bookAuthor;
    long long bookISBN;

    // Try to open file
    inputFS.open("/Users/brash/CLionProjects/cpsc256/Examples/Week11/BookLibraryZybooks/books.txt");

    while(getline(inputFS, bookTitle)) {
        inputFS >> bookISBN;
        inputFS.ignore(1, '\n');
        getline(inputFS, bookAuthor);
        cout << "Title: " << bookTitle << endl;
        cout << "ISBN: " << bookISBN << endl;
        cout << "Author: " << bookAuthor << endl;

        // Insert into linked list
        currNode = new BookNode(bookTitle, bookAuthor, bookISBN);
        linkedListOperations = linkedListLibrary.InsertSorted(currNode, linkedListOperations);

        // Insert into vector
        tempBook = Book(bookTitle, bookAuthor, bookISBN);
        vectorOperations = vectorLibrary.InsertSorted(tempBook, vectorOperations);

        cout << "Number of linked list book copy operations: " << linkedListOperations << endl;
        cout << "Number of vector book copy operations: " << vectorOperations << endl;

    }

    inputFS.close(); // close() may throw ios_base::failure if fails

}

int main (int argc, const char* argv[]) {
   int linkedListOperations = 0;
   int vectorOperations = 0;

   // Create libraries
   LinkedListLibrary linkedListLibrary = LinkedListLibrary();
   VectorLibrary vectorLibrary;

   // Fill libraries with 100 books
   FillLibraries(linkedListLibrary, vectorLibrary);

    // Create new book to insert into libraries
   BookNode* currNode;
   Book tempBook;

   string bookTitle;
   string bookAuthor;
   long bookISBN;

   cout << "Enter the book title: " << endl;
   getline(cin, bookTitle);
   cout << "Enter the 13 digit ISBN number: " << endl;
   cin >> bookISBN;
   cin.ignore();
   cout << "Enter the book author: " << endl;
   getline(cin, bookAuthor);

    // Insert into linked list
    // No need to delete currNode, deleted by LinkedListLibrary destructor
    currNode = new BookNode(bookTitle, bookAuthor, bookISBN);
    // TODO: Call LL_Library's InsertSorted() method to insert currNode and return
    //       the number of operations performed

    linkedListOperations = linkedListLibrary.InsertSorted(currNode, linkedListOperations);

    // Insert into VectorList
    tempBook  = Book(bookTitle, bookAuthor, bookISBN);
    // TODO: Call VectorLibrary's InsertSorted() method to insert tempBook and return
    //       the number of operations performed
    vectorOperations = vectorLibrary.InsertSorted(tempBook, vectorOperations);

    // TODO: Print number of operations for linked list
    cout << "Number of linked list book copy operations: " << linkedListOperations << endl;
    // TODO: Print number of operations for vector
    cout << "Number of vector book copy operations: " << vectorOperations << endl;

    return 0;

}

