/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/main.cc to edit this template
 */

/* 
 * File:   main.cpp
 * Author: 00465510
 *
 * Created on December 7, 2021, 8:14 PM
 */

#include <iostream>
#include <vector>
#include <string>

using namespace std;
 
class BST
{
    int data;
    BST* left;
    BST* right;
 
public:
    // Default constructor.
    BST();
 
    // Parameterized constructor.
    BST(int);
 
    // Insert function.
    BST* Insert(BST*, int);
 
    // Inorder traversal.
    string Inorder(BST*);

    // Find an element in the tree
    bool Find(BST*, int);
    
    int maxDepth(BST*);
    
    int GetData() {return data;}
   
    
};
 
// Default Constructor definition.
BST ::BST()
    : data(0)
    , left(NULL)
    , right(NULL)
{
}
 
// Parameterized Constructor definition.
BST ::BST(int value)
{
    data = value;
    left = right = NULL;
}

 
// Insert function definition.
BST* BST ::Insert(BST* root, int value)
{
    if (!root)
    {
        // Insert the first node, if root is NULL.
        return new BST(value);
    }
 
    // Insert data.
    if (value > root->data)
    {
        // Insert right node data, if the 'value'
        // to be inserted is greater than 'root' node data.
 
        // Process right nodes.
        root->right = Insert(root->right, value);
    }
    else
    {
        // Insert left node data, if the 'value'
        // to be inserted is greater than 'root' node data.
 
        // Process left nodes.
        root->left = Insert(root->left, value);
    }
 
    // Return 'root' node, after insertion.
    return root;
}
 
// Inorder traversal function.
// This gives data in sorted order.
string BST ::Inorder(BST* root)
{
    string s = "";
    if (!root) {
        return s;
    }
    s = s + Inorder(root->left);
    s = s + to_string(root->data) + " ";
    s = s + Inorder(root->right);
    
    return s;
}

int BST ::maxDepth(BST* root)
{
    if (root == NULL)
        return 0;
    else
    {
        /* compute the depth of each subtree */
        int lDepth = maxDepth(root->left);
        int rDepth = maxDepth(root->right);
     
        /* use the larger one */
        if (lDepth > rDepth)
            return(lDepth + 1);
        else return(rDepth + 1);
    } 
}

bool BST::Find(BST* root, int value) {
    if (!root) {
        return false;
    }
    if (root->data == value) {
        return true;
    }
    if (value > root->data) {
        return Find(root->right, value);
    }
    else {
        return Find(root->left, value);
    }
}

// Driver code
int main()
{
    
    vector<int> elements;

    int num_elements = 100000;
    int rand_size = 100000;

    for (int i=0; i<num_elements; i++) {
        int j = rand() % rand_size;
        elements.push_back(j);
    }

    /*elements.push_back(44);
    elements.push_back(34);
    elements.push_back(18);
    elements.push_back(51);
    elements.push_back(17);
    elements.push_back(20);
    elements.push_back(12);
    elements.push_back(40);*/
    
    
    BST b;
    BST* root = NULL;

    root = b.Insert(root, elements[0]);
    //cout << "After adding " << elements[0] << ", the tree has " << b.Inorder(root) << endl;
    //cout << "The height of the tree is " << b.maxDepth(root) << endl;

    for (unsigned int i = 1; i<elements.size(); i++) {
        b.Insert(root,elements[i]);
        //cout << "After adding " << elements[i] << ", the tree has " << b.Inorder(root) << endl;
        //cout << "The height of the tree is " << b.maxDepth(root) << endl;
    }

    //cout << "The tree has " << b.Inorder(root) << endl;

    cout << "The height of the tree is " << b.maxDepth(root) << endl;

    double duration_bst_fps = 0.0;
    double duration_vec_fps = 0.0;
    double duration_vecbst_fps = 0.0;

    sort(elements.begin(), elements.end());

    for (int i=0; i<1000; i++) {
        int search_for = rand() % rand_size;

        auto startl = chrono::high_resolution_clock::now();
        bool found = b.Find(root, search_for);
        //cout << "Searching the tree for " << search_for << "   =   " << found << endl;
        auto stopl = chrono::high_resolution_clock::now();
        chrono::duration<double,micro> duration_bst_fp = stopl - startl;
        duration_bst_fps += double(duration_bst_fp.count());

        auto startv = chrono::high_resolution_clock::now();
        if (std::find(elements.begin(), elements.end(), search_for)!=elements.end()) {
            //cout << "Found " << search_for << " using std::find" << endl;
        } else {
            //cout << "Did not find " << search_for << " using std::find" << endl;
        }
        auto stopv = chrono::high_resolution_clock::now();
        chrono::duration<double,micro> duration_vec_fp = stopv - startv;
        duration_vec_fps += double(duration_vec_fp.count());

        auto startvb = chrono::high_resolution_clock::now();
        if (std::binary_search(elements.begin(), elements.end(), search_for)) {
            //cout << "Found " << search_for << " using std::binary_search" << endl;
        } else {
            //cout << "Did not find " << search_for << " using std::binary_search" << endl;
        }
        auto stopvb = chrono::high_resolution_clock::now();
        chrono::duration<double,micro> duration_vecbst_fp = stopvb - startvb;
        duration_vecbst_fps += double(duration_vecbst_fp.count());

    }

    cout << "Time (useconds) for BST Operations: " << duration_bst_fps << endl;
    cout << "Time (useconds) for Vector Operations: " << duration_vec_fps << endl;
    cout << "Performance Factor Unsorted Vector: " << 1.0*duration_vec_fps/duration_bst_fps << endl;

    cout << "Time (useconds) for Vector BST Operations: " << duration_vecbst_fps << endl;
    cout << "Performance Factor Sorted Vector BST: " << 1.0*duration_vecbst_fps/duration_bst_fps << endl;

    return 0;
}
