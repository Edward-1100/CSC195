#include <iostream>
using namespace std;

// ** REFERENCE PARAMETER **
void Square(int &i)
{
    i = i * i;
}

// ** POINTER PARAMETER **
void Double(int* i)
{
    *i = *i * 2;
}

int main()
{
    // ** REFERENCE **

    // declare an int variable and set the value to some number (less than 10)
    int num = 3;

    // declare a int reference and set it to the int variable above
    int &ref = num;

    // output the int variable
    cout << "Original Value: " << num << endl;

    // set the int reference to some number
    ref = 8;

    // output the int variable
    cout << "Updated Value (Reference): " << num << endl;

    // what happened to the int variable when the reference was changed? (insert answer)
    //// The int was updated because the reference targets the same place in  memory

    // output the address of the int variable
    cout << "Address of Num: " << &num << endl;

    // output the address of the int reference
    cout << "Address of Ref: " << &ref << endl;

    // are the addresses the same or different? (insert answer)
    //// The Same

    // ** REFERENCE PARAMETER **

    // call the Square function with the int variable created in the REFERENCE section
    Square(num);

    // output the int variable to the console
    cout << "Value After Square: " << num << endl;

    // !! notice how the calling variable has now changed, this is because we 'passed by reference' !!
    // !! when a function takes a reference parameter, any changes to the parameter changes the calling variable !!

    // ** POINTER VARIABLE **

    // declare an int pointer, set it to nullptr (it points to nothing)
    int* ptr = nullptr;

    // set the int pointer to the address of the int variable created in the REFERENCE section
    ptr = &num;

    // output the value of the pointer
    cout << "Pointer address: " << ptr << endl;

    // what is this address that the pointer is pointing to? (insert answer)
    //// It is the adress of num

    // output the value of the object the pointer is pointing to (dereference the pointer)
    cout << "Value From Pointer: " << *ptr << endl;

    // ** POINTER PARAMETER **

    // call the Double function with the pointer created in the POINTER VARIABLE section
    Double(ptr);

    // output the dereference pointer
    cout << "Value After Double: " << *ptr << endl;

    // output the int variable created in the REFERENCE section
    cout << "Value of num after Double : " << num << endl;

    // did the int variable's value change when using the pointer?
    //// Yes, the value was updated by the pointer

    return 0;
}
