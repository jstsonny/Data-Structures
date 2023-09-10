######PEOPLE ARE IN LINE FOR NEW PHONES: IPHONE (1), GALAXY (0). THE PHONES ARE IN A STACK AND CUSTOMERS ARE IN A QUEUE#####
######IF A CUSTOMER IS IN FRONT OF THE QUEUE AND THEIR DESIRED PHONE IS NOT ON TOP OF STACK, THEY GO TO THE BACK OF THE LINE######
######THE PROGRAM WILL PROVIDE US WITH HOW MANY CUSTOMERS WERE NOT ABLE TO GET THE PHONE THEY DESIRED#######

#include "phonequeue.h"
#include "phonestack.h"
#include <iostream>

using namespace std;

int main()
{

    Stack *phones = new Stack();

    cout << "Queue of customers: " << endl;
    //creating queue
    StrToQueue();

    cout << "Stack of phones: " << endl;

    //creating phone stack
    phones->strToStack();

    //operating store
    buysPhone(phones);
    
    //custoemrs left in queue
    cout << Qlength() << " people did not get a new phone." << endl;

    return 0;
}