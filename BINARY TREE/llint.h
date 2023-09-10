#ifndef LLINT_H
#define LLINT_H

#include <iostream>
#include <string>
#include <sstream>

using namespace std;

class IntNode
{
public:
    int ldata;
    IntNode* next;
};
void addIntNodeEnd(IntNode* head, int newldata){
    
    //prep new IntNode
    IntNode* newIntNode = new IntNode();
    newIntNode->ldata = newldata;
    newIntNode->next = NULL;

    //if empty, make head
    if (!head){
        head = newIntNode;
        return;
    }

    //find last
    IntNode* last = head;
    while (last->next!=NULL){
        last = last->next;
    }
    
    //insert after last
    last->next = newIntNode;
}
void printIt(IntNode* myList){
    if (!myList) cout << "[]";
    else
    {
        cout << "[";
        while (myList->next){
            cout << myList->ldata << ", ";
            myList = myList->next;
        }
        cout << myList->ldata << "]";
    }
    cout << endl;
}   

IntNode* removeFirstNode(IntNode* head)
{
    if (head == NULL)
        return NULL;
 
    // Move the head pointer to the next node
    IntNode* temp = head;
    head = head->next;
 
    delete temp;
 
    return head;
}

#endif