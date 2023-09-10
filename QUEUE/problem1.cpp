#####QUEUE IMPLEMENTATION WITH CUSTOMERS AS THE MONEY BILL THEY ARE HOLDING#########
#####STANDING IN LINE FOR A 5 DOLLAR SANDWICH STAND WHERE BILLS ARE STORED #########
#####IN THE LINKED-LIST REGISTER. THE PROCESS STOPS WHEN THERES NOT AN APP-#########
#####ROPRIATE AMOUNT OF BILLS TO GIVE THE CUSTOMER THE RIGHT AMT OF CHANGE.########
#include <iostream>
#include <string>
#include <sstream>

#include "register.h"

using namespace std;

struct node
{
int data;
struct node *next;
};

struct node* front = NULL;
struct node* rear = NULL;
struct node* temp;

void Insert(int val)
{
    if (rear == NULL)
    {
        rear = new node;
        rear->next = NULL;
        rear->data = val;
        front = rear;
    } 
    else 
    {
        temp = new node;
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
        cout<<"Bill that left the queue: $"<<front->data<<endl;
        free(front);
        front = temp;
    }

    else 
    {
        cout<<"Bill that left the queue: $"<<front->data<<endl;
        free(front);
        front = NULL;
        rear = NULL;
    }
}
void Display() 
{        
    temp = front;

    if ((front == NULL) && (rear == NULL))
    {
        cout<<"Queue is empty"<<endl;
        return;
    }

    while (temp != NULL)
    {
    cout<<temp->data<<" "; 
    temp = temp->next;
    }

    cout<<endl;
}    

void StrToList()
{
    int num;
    string input;

    getline(cin, input);
    istringstream iss(input);
    while(iss >> num)
    {
        Insert(num);
    }
}
bool Change(Slot* Register, int money){

    int change = 0;

    bool enoughCash = false;
    Slot* tempReg = Register;
    // IFS

    if (money == 50)
    {
        while (tempReg && change < 45)
        
        {
            while (change <= 40){

                if (tempReg->data == 20)
                {
                    change += tempReg->data;
                }
                tempReg = tempReg->next;

                if (!tempReg || change == 40) break;
            }
            tempReg = Register;
            if (change != 40)
            {
                while (change <= 40)
                {
                    if (tempReg->data == 10)
                    {
                        change += tempReg->data;
                    }
                    tempReg = tempReg->next;

                    if (!tempReg || change == 40) break;
                }
            }
            
            tempReg = Register;
            while (change <= 45)
            {
                if (tempReg->data == 5)
                {
                    change += tempReg->data;
                }
                tempReg = tempReg->next;

                if (!tempReg || change == 45) break;
            }
        }

        if (change == 45) enoughCash = true;

        else enoughCash = false;
        tempReg = Register;
    }
    
    if (money == 20)
    {
        while (tempReg && change < 15)
        {
            while (change <= 10)
            {
                if (tempReg->data == 10)
                {
                    change += tempReg->data;
                }
                tempReg = tempReg->next;

                if (!tempReg || change == 10) break;
            }
            
            tempReg = Register;
            while (change <= 15)
            {
                if (tempReg->data == 5)
                {
                    change += tempReg->data;
                }
                tempReg = tempReg->next;

                if (!tempReg || change == 15) break;
            }
        }

        if (change == 15) enoughCash = true;

        else enoughCash = false;
        tempReg = Register;
        
    }
    
    if (money == 10)
    {
        while (tempReg && change < 5)
        {
            while (change <= 5)
            {
                if (tempReg->data == 5) change += tempReg->data;
                tempReg = tempReg->next;
                if (!tempReg || change == 5) break;
            }
        }

        if (change == 5) enoughCash = true;

        else enoughCash = false;
        tempReg = Register;
    }

    if (money == 5){
        enoughCash = true;
    }
    
    return enoughCash;
}
Slot* UpdateRegister(Slot* Register, int money){

    int change = 0;
    Slot* tempReg = Register;

    // IFS

    if (money == 50)
    {
        while (tempReg && change < 45)
        
        {
            while (change <= 40){

                if (tempReg->data == 20)
                {
                    change += tempReg->data;
                    removeBill(&Register, 20);
                }
                tempReg = tempReg->next;

                if (!tempReg || change == 40) break;
            }
            
            tempReg = Register;
            if (change != 40)
            {    while (change <= 40)
                {
                    if (tempReg->data == 10)
                    {
                        change += tempReg->data;
                        removeBill(&Register, 10);
                    }
                    tempReg = tempReg->next;

                    if (!tempReg || change == 40) break;
                }
            }
            
            tempReg = Register;
            while (change <= 45)
            {
                if (tempReg->data == 5)
                {
                    change += tempReg->data;
                    removeBill(&Register, 5);
                }
                tempReg = tempReg->next;

                if (!tempReg || change == 45) break;
            }
        }

        if (change == 45) 
        {
            addSlotEnd(&Register, 50);
        }

        tempReg = Register;
    }
    
    if (money == 20)
    {
        while (tempReg && change < 15)
        {
            while (change <= 10)
            {
                if (tempReg->data == 10)
                {
                    change += tempReg->data;
                    removeBill(&Register, 10);
                }
                tempReg = tempReg->next;

                if (!tempReg || change == 10) break;
            }
            
            tempReg = Register;
            while (change <= 15)
            {
                if (tempReg->data == 5)
                {
                    change += tempReg->data;
                    removeBill(&Register, 5);
                }
                tempReg = tempReg->next;

                if (!tempReg || change == 15) break;
            }
        }

        if (change == 15)
        {
            addSlotEnd(&Register, 20);
        }
        tempReg = Register;
        
    }
    
    if (money == 10)
    {
        while (tempReg && change < 5)
        {
            while (change <= 5)
            {
                if (tempReg->data == 5)
                {   
                    change += tempReg->data;
                    removeBill(&Register, 5);
                } 

                tempReg = tempReg->next;
                if (!tempReg || change == 5) break;
            }
        }

        if (change == 5){
            addSlotEnd(&Register, 10);
        }

        tempReg = Register;
    }

    if (money == 5){
        addSlotEnd(&Register, 5);
    }
    
    return Register;
}
int main()
{

    StrToList();

    // Create register list
    Slot* Register = new Slot();
    Register->data = 5;

    cout << "Cash Drawer: ";
    printList(Register);
    cout << endl;

    
    bool enoughChange; 

    while (front)
    {
        cout << "next in line: $" << front->data << endl;
        enoughChange = Change(Register, front->data);

        if (enoughChange){
            Register = UpdateRegister(Register, front->data);
            Delete();
            cout << endl;
            cout << "Cash Drawer: ";
            printList(Register);
            cout << endl;
        }

        else break;

    }

    if (enoughChange) cout << "1: John had the right amount of change for all transactions." << endl;
    else cout << "0: John does not have change for a " << front->data << "." << endl;

    return 0;
}