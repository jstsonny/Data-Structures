#ifndef FIXNOTCLASS_H
#define FIXNOTCLASS_H

#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

struct Node
{
    Node *next;
    char data;    
};

class Stack
{
private:
    Node *top;
public:
    Stack();
    ~Stack();
    void push(char dat);
    bool stackEmpty();
    char pop();
    void printStack();
    string inToPre(string s);
    string inToPost(string s);
    int evalPost(string s);
    bool isOperator(char c);
    int preced(char c);

    
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
void Stack::push(char dat)
{
    Node *temp = new Node;
    temp->data = dat;
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
char Stack::pop(){
    if (!stackEmpty())
    {
        char topdata = top->data;
        Node *temptop = top;
        top = temptop->next;
        delete temptop;
        return topdata;
    }
    else
    return 0;
}

void Stack::printStack(){
    if (!stackEmpty())
    {
        while (top != NULL){
            cout << top->data;
            top = top->next;
        }
        cout << endl;
        return;
    }
    else
    return;

}

string Stack::inToPre(string s){
        
        string prefix;
        string infix = s;

        reverse(infix.begin(),infix.end());

        for (int i = 0; i < infix.length(); i++)
        {
            if(infix[i] >= '1' && infix[i] <= '9'){
                prefix += infix[i];
            }

            else if (isOperator(infix[i]))
            {
                if(stackEmpty())
                {
                    push(infix[i]);
                }
                else
                {
                    if(preced(infix[i])>preced(top->data))
                    {
                        push(infix[i]);
                    }
                    else if(preced(infix[i]) == preced(top->data)){
                        push(infix[i]);
                    }
                    else
                    {
                        while((!stackEmpty())&&(preced(infix[i]))<preced(top->data)){
                            prefix += pop();
                        }
                        push(infix[i]);
                    }
                }
            }
            
        }
        while (!stackEmpty()){
            prefix += pop();
        }

        reverse(prefix.begin(),prefix.end());

        
        return prefix;
}

string Stack:: inToPost(string s){
    string postfix;
    string infix = s;

    for (int i = 0; i < infix.length(); i++)
    {
        if (infix[i] >= '0' && infix[i] <= '9')
        {
            postfix += infix[i];
        }
        else
        {
            if (stackEmpty())
            {
                push(infix[i]);
            }
            else if (isOperator(infix[i]))
            {
                if(preced(infix[i]) > preced(top->data))
                {
                    push(infix[i]);
                }
                else
                {
                    while ((!stackEmpty()) && (preced(infix[i])) <= preced(top->data))
                    {
                        postfix += pop();
                    }
                    push(infix[i]);

                }
            }       
        }
    }
    while (!stackEmpty())
    {
        postfix += pop();
    }
    return postfix;
}

int Stack::evalPost(string s){
    
    string postfix = s;

    for (int i = 0; i < postfix.length(); i++)
    {
        if (!isOperator(postfix[i]))
        {
            int k = postfix[i] - '0';
            push(k);
        }
        
        else
        {
            int v1 = pop();
            int v2 = pop();
            
            if (postfix[i] == '+'){
                push(v2+v1);
            }
            else if (postfix[i] == '-'){
                push(v2-v1);
            }
            else if (postfix[i] == '*'){
                push(v2*v1);
            }
            else if (postfix[i] == '/'){
                push(v2/v1);
            }
        }
    }
    return pop();
        
}

bool Stack::isOperator(char c){
    if (c == '-' || c == '+' || c == '*' || c == '/')
        return true;
    else
        return false;
}

int Stack::preced(char c){
    switch (c)
    {
        case '-':
        case '+':
            return 1;
            break;

        case '*':
        case '/':
            return 5;
            break;
        
        default:
            return -1;
            break;
    }
}
#endif