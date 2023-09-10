#include "bst.h"
#include <sstream>
#include <string>
#include <algorithm>

BST StringToBST()
{  
    BST tree;

    int num;
    string input;
    
    cout << "Type string for BST: " << endl;

    getline (cin, input);
    istringstream iss(input);

    while (iss >> num)
    {
        TreeNode *newTN = new TreeNode(num);
        tree.insertNode(newTN);
    }
    return tree;
}

int main()
{
    BST myTree = StringToBST();

    if (myTree.root->data % 2 == 0) myTree.postPrint(myTree.root);
    else myTree.prePrint(myTree.root);

    cout << endl << "Enter n: " << endl;

    int n;
    cin >> n;
    int c = 0;

    cout << "nth largest element: ";
    myTree.nthLargest(myTree.root, n, c);

    return 0;
}