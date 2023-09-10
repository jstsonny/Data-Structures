#ifndef PHONEQUEUE_H
#define PHONEQUEUE_H

#include <iostream>
#include <string>
#include <algorithm>
#include <sstream>

#include "phonestack.h"

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

void StrToQueue()
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

int Qlength(){
    temp = front;
    int length = 0;
    
    while (temp){
        length +=1;
        temp = temp->next;
    }

    return length;
}

bool AnyBuyers(int n){

    temp = front;

    while (temp)
    {

        if (temp->data == n)
            return true;
        
        else 
        {
            temp = temp->next;
        }
    }

    return false;

}

void buysPhone(Stack *phones)
{
    Stack *phone = phones;

    while (AnyBuyers(phone->topPhone()) && !phone->stackEmpty() && front != NULL)
    {
       if (phone->topPhone() == front->data)
        {
            phone->pop();
            Delete();
        }

        else
        {
            Insert(front->data);
            Delete();
            if (AnyBuyers(phone->topPhone()) == false)
                break;
        }
    }
    return;
}


#endif