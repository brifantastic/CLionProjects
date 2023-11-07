#include "MileageTrackerNode.h"
#include <string>
#include <iostream>
using namespace std;

int main () {
    // References for MileageTrackerNode objects
    MileageTrackerNode* headNode;
    MileageTrackerNode* currNode;
    MileageTrackerNode* lastNode;

    double miles;
    string date;
    int i;

    // Front of nodes list
    headNode = new MileageTrackerNode();
    lastNode = headNode;

    // TODO: Read in the number of nodes
    int input;
    cin >> input;
    cin.ignore();

    // TODO: For the scanned number of nodes, scan
    //       in data and insert into the linked list
    for(i = 0; i < input; i++ ) {
        cin >> miles;
        cin.ignore();
        getline(cin, date);
        currNode = new MileageTrackerNode(miles, date);
        lastNode->InsertAfter(currNode);
        lastNode = currNode;
    }

    // TODO: Call the PrintNodeData() method
    //       to print the entire linked list
    currNode = headNode->GetNext();
    while (currNode != nullptr) {
        currNode->PrintNodeData();
        currNode = currNode->GetNext();
    }

    // MileageTrackerNode Destructor deletes all
    //       following nodes
    delete headNode;

    return 0;
}