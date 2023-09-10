#########CREATE SINGLY LINKED LIST FOR A STRING OF INTEGERS, REMOVE THE SMALLEST ELEMENT, REVERSE THE LIST##########
#include <iostream>
#include <sstream>

using namespace std;

class Slot
{
public:
    int data;
    Slot* next;
};

void addSlotEnd(Slot** headSlot, int data)
{
   
    // 1. allocate Slot
    Slot* new_Slot = new Slot();
 
    // 2. put in the data
    new_Slot->data = data;
 
    // 3. Make next of new Slot as head
    new_Slot->next = (*headSlot);
 
    // 4. Move the head to point to
    // the new Slot
    (*headSlot) = new_Slot;
}

void printList(Slot* headSlot){
    cout << "[";
    while (headSlot->next!=NULL){
        cout << headSlot->data << ", ";
        headSlot = headSlot->next;
    }
    cout << headSlot->data << "]" << endl;

}

int findSmallest(Slot* headSlot){
    int smallest = headSlot->data;
    while (headSlot)
    {
        if (headSlot->data < smallest)
        {
            smallest = headSlot->data;
        }

        headSlot = headSlot->next;

    }
    return smallest;
}

Slot* removeSmallest(Slot* headSlot, int small){
    
    int smallest = small;
    if (!headSlot) 
    return headSlot;

    while (headSlot && headSlot->data == smallest)
    {
        headSlot = headSlot->next;
    }
    
    Slot* temp = headSlot;

    while (temp)
    {
        if (temp->next && temp->next->data == smallest)
        {
            temp->next = temp->next->next;
        }
        else
            temp = temp->next;
    }

    return headSlot;

}

Slot* reverseList(Slot* headSlot)
    {
        Slot *curr = headSlot;
        Slot *prev = NULL;
        Slot *temp;
 
        while (curr) {
            
            temp = curr->next;
           
            curr->next = prev;
            
            prev = curr;
            curr = temp;
        }
        return prev;
    }

Slot* initList(){
    int num;
    string input;
    Slot* head = new Slot();
    cin >> head->data;

    
    getline(cin, input);
    istringstream iss(input);
    while(iss >> num)
    {
        addSlotEnd(head, num);
    }
    return head;
}

int main(){

    Slot* myList = initList();

    myList = removeSmallest(myList, findSmallest(myList));

    myList = reverseList(myList);


    printList(myList);

    //printList(reverseList(removeSmallest(head, findSmallest(head))));
    

    return 0;
}