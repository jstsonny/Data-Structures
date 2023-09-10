####BINARY TREE FOR STRING OF INTEGERS. CHECKS THE SUM COLLECTED FOR ROOT-LEAF PATHS AND CHECKS IF INPUT INT #####
####IS IN THAT LIST OF PATH SUMS. RETURNS 1 IF YES, 0 IF NO#####
#include "ll.h"
#include "llint.h"

struct TreeNode
{
    int treedata;
    struct TreeNode *right,*left;
};

struct TreeNode *root;

struct QNode
{
TreeNode* data;
struct QNode *next;
};

struct QNode* front = NULL;
struct QNode* rear = NULL;
struct QNode* temp;

//Q functions
void Insert(TreeNode* val)
{
    if (rear == NULL)
    {
        rear = new QNode;
        rear->next = NULL;
        rear->data = val;
        front = rear;
    } 
    else 
    {
        temp = new QNode;
        rear->next = temp;
        temp->data = val;
        temp->next = NULL;
        rear = temp;
    }
}
void Delete()
{
    temp = front;

    if (front == NULL)
    {
        cout<<"Queue is empty!!"<<endl; } 
        
    else if (temp->next != NULL) 
    {
        temp = temp->next;
        //cout<<"deleted from queue: "<<front->data<<endl;
        free(front);
        front = temp;
    }

    else 
    {
        //cout<<"deleted from queue: "<<front->data<<endl;
        free(front);
        front = NULL;
        rear = NULL;
    }
}

// Tree functions
TreeNode* newTree(int val){
    struct TreeNode *tempRoot = new TreeNode;
    tempRoot->treedata = val;
    tempRoot->left = NULL;
    tempRoot->right = NULL;
    return tempRoot;
}

void llToTree(LNode *head, TreeNode* &root){
    
    if (head == NULL){
    root = NULL;
    return;}

    root = newTree(stoi(head->ldata));
    Insert(root);

    head = head->next;

    while (head)
    {
        TreeNode* dad = front->data;
        Delete();

        TreeNode* leftOne = NULL;
        TreeNode* rightOne = NULL;

        if (head->ldata != "null")
        {
            leftOne = newTree(stoi(head->ldata));
            Insert(leftOne);
        }

        head = head->next;

        if (head)
        {
                if (head->ldata != "null")
            {
                rightOne = newTree(stoi(head->ldata));
                Insert(rightOne);
            }
            head = head->next;
        }

        dad->left = leftOne;
        dad->right = rightOne;
        


    }


}

void printTree(TreeNode* root)
{
    if (root)
    {
        cout << root->treedata << " ";
        printTree(root->left );
        printTree(root->right );
    }
}

void recursiveSum(TreeNode *root, int sum, IntNode* &sumHead){
    
    if (!root) return;

    sum += root->treedata;

    if (!root->left && !root->right) 
    {
        addIntNodeEnd(sumHead, sum);
        return;
    }

    recursiveSum(root->left, sum, sumHead);
    recursiveSum(root->right, sum, sumHead);


}
IntNode *PathSum(TreeNode* root)
{
    IntNode* sumHead = new IntNode();

    recursiveSum(root, 0, sumHead);
 
    sumHead = removeFirstNode(sumHead);
    // Printing all the path sum
    cout << "List of sums: " << endl;
    printIt(sumHead);

    return sumHead;
}

bool AnyPaths(TreeNode* root, int num){
    IntNode* sums = PathSum(root);

    while (sums)
    {
        if (sums->ldata == num) return true;

        else sums = sums->next;
    }
    return false;
    
}

        
int main(){

    cout << "Input numbers for Binary Tree: " << endl;
    //load linked list with numbers
    LNode* head = initList();
    
    int number;
    cout << "Input number to check for path sums: " << endl;
     cin >> number;
    
    // loads linked list items in to Binary Tree in level order
    llToTree(head, root);
    
    cout << "Tree in PreOrder: " << endl;
    printTree(root);
    cout << endl;

    // create linked list, each node representing the sum of a root-to-leaf path. evaluates if any sum is equal to user input.
    if (AnyPaths(root, number)) cout << "1";
    else cout << "0";

    cout << endl;

    return 0;
}