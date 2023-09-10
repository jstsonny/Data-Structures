#ifndef REGISTER_H
#define REGISTER_H
#include <iostream>

using namespace std;

class Slot
{
public:
    int data;
    Slot* next;
};
void addSlotEnd(Slot** headSlot, int data)
{
   
    Slot* new_Slot = new Slot();

    new_Slot->data = data;

    new_Slot->next = (*headSlot);
 
    (*headSlot) = new_Slot;

    cout << "$" << data << " added to drawer" << endl;
}
void printList(Slot* headSlot){
    
    if (!headSlot)
    {
        cout << "[]" << endl;
    }
    
    else{


    cout << "[";
    while (headSlot->next!=NULL){
        cout << headSlot->data << ", ";
        headSlot = headSlot->next;
    }
    cout << headSlot->data << "]" << endl;
    }

}
void removeBill(Slot** head, int bill)
{

    Slot* temp = *head;
    Slot* prev = NULL;
 
    if (temp != NULL && temp->data == bill) 
    {
       

        *head = temp->next;

        delete temp;

        cout << "$" << bill << " removed from drawer" << endl;

        return;
    }
 
    else 
    {
        while (temp != NULL && temp->data != bill) 
        {
            prev = temp;
            temp = temp->next;
        }
 
        if (temp == NULL)
            return;
 
        prev->next = temp->next;
 
        delete temp;
        cout << "$" << bill << " removed from drawer" << endl;

    }
}
 
#endif