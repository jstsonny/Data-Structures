#ifndef TREENODE_H
#define TREENODE_H

#include <iostream>

using namespace std;

class TreeNode
{
    public:
        int data;
        TreeNode* left;
        TreeNode* right;

        TreeNode();
        TreeNode(int v);
};
TreeNode::TreeNode()
{
    data = 0;
    left = NULL;
    right = NULL;
}

TreeNode::TreeNode(int v)
{
    data = v;
    left = NULL;
    right = NULL;
}
#endif