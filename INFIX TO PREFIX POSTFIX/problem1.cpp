#include <iostream>
#include "fixnotclass.h"
using namespace std;

int main(){
    Stack *stagg = new Stack();
    string s;
    cin >> s;

    cout << stagg->inToPre(s) << endl;
    cout << stagg->inToPost(s) << endl;
    cout << stagg->evalPost(stagg->inToPost(s));
    
    return 0;
}