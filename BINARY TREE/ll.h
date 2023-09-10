#ifndef LL_H
#define LL_H

#include <iostream>
#include <string>
#include <sstream>

using namespace std;

class LNode
{
public:
    string ldata;
    LNode* next;
};
void addLNodeEnd(LNode* head, string newldata){
    
    //prep new Lnode
    LNode* newLNode = new LNode();
    newLNode->ldata = newldata;
    newLNode->next = NULL;

    //if empty, make head
    if (!head){
        head = newLNode;
        return;
    }

    //find last
    LNode* last = head;
    while (last->next!=NULL){
        last = last->next;
    }
    
    //insert after last
    last->next = newLNode;
}
void printIt(LNode* myList){
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
LNode* initList(){
    string num;
    string input;
    LNode* head = new LNode();
    cin >> head->ldata;

    
    getline(cin, input);
    istringstream ss(input);
    while(ss >> num)
    {
        addLNodeEnd(head, num);
    }
    return head;
}

#endif