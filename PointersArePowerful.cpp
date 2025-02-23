#include <iostream>
using namespace std;

int main() {
    int a = 10;        
    int* p = &a;       

    cout << "Address of 'a' stored in pointer p: " << p << endl;

    cout << "Value of 'a' using pointer p: " << *p << endl;

    *p = 27;

    cout << "New value of 'a' after using pointer p: " << a << endl;

    return 0;
}