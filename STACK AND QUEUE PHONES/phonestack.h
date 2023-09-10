#ifndef PHONESTACK_H
#define PHONESTACK_H

#include <iostream>
#include <string>
#include <sstream>
#include <algorithm>

using namespace std;

struct Phone
{
    Phone *next;
    int model;    
};

class Stack
{
private:
    Phone *top;
public:
    Stack();
    ~Stack();
    void push(int mod);
    bool stackEmpty();
    int pop();
    void printStack();
    void strToStack();
    int topPhone();
};

Stack::Stack()
{
    //initialize empty stack
    top = NULL;
}

Stack::~Stack()
{
    cout << "deleting.." << endl;
}
void Stack::push(int mod)
{
    Phone *temp = new Phone;
    temp->model = mod;
    temp->next = top;

    top = temp;
}
bool Stack::stackEmpty()
{
    if (top == NULL)
        return true;
    else
        return false;
}
int Stack::pop(){
    if (!stackEmpty())
    {
        int topmodel = top->model;
        Phone *temptop = top;
        top = temptop->next;
        delete temptop;
        return topmodel;
    }
    else
    return 5;
}

void Stack::printStack(){
    if (!stackEmpty())
    {
        while (top != NULL){
            cout << top->model << " ";
            top = top->next;
        }
        cout << endl;
        return;
    }
    else
    return;

}

void Stack::strToStack()
{
    int num;
    string input;
    getline(cin, input);
    reverse(input.begin(), input.end());
    istringstream iss(input);
    while(iss >> num)
    {
        push(num);
    }
}

int Stack::topPhone(){
    
    if (!stackEmpty()) return top->model;

    else return 5;
}


#endif