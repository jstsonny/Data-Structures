#ifndef BST_H
#define BST_H
#include "treenode.h"


using namespace std;

class BST
{
    public:
        TreeNode* root;

        BST()
        {
            root = NULL;
        }

        bool isEmpty()
        {
            if (!root) return true;
            else return false;
        }

        void insertNode(TreeNode *newNode)
        {
            if (!root) root = newNode;

            else
            {
                TreeNode *temp = root;

                while (temp)
                {
                    if (newNode->data == temp->data) return;

                    else if ((newNode->data < temp->data) && (!temp->left))
                    {
                        temp->left = newNode;
                        break;
                    }

                    else if ((newNode->data > temp->data) && (!temp->right))
                    {
                        temp->right = newNode;
                        break;
                    }

                    else temp = temp->right;

                }

            }
        }

        void prePrint(TreeNode* root)
        {
            if (!root) return;

            cout << root->data << " ";

            prePrint(root->left);

            prePrint(root->right);
        }

        void postPrint(TreeNode* root)
        {
            if (!root) return;

            postPrint(root->left);

            postPrint(root->right);

            cout << root->data << " ";
        }

        void inPrint(TreeNode* root){

            if (!root) return;

            inPrint(root->left);

            cout << root->data << " ";

            inPrint (root->right);
        }

        void nthLargest(TreeNode *root, int n, int &c)
        {
            if (!root || c >= n ) 
                return;
        

            nthLargest(root->right, n, c);
            
            c++;

            if (c == n)
            {
                cout << root->data << endl;
                return;
            }
        
            nthLargest(root->left, n, c);
        }
};
#endif