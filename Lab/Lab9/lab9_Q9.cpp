// C++ program to convert a decimal
// number to binary number

#include <iostream>
using namespace std;

//Stack to store the binary numbers
int mStack[32];
int top=-1;

//push values to the top of the stack
void push(int value){
    if(top<32){
        ++top;
        mStack[top]=value;
    }
    else
        cout<<"Stack overflow \n";
}

// Remove in reverse order
int pop(){
int delValue;
if(top>-1){
        delValue= mStack[top];
        --top;
}
else
{
    cout<<"Stack underflow \n";
    //delValue= '\n';
}
return delValue;
}
// function to convert decimal to binary
void decToBinary(int n)
{

    while (n > 0) {

        // storing remainder in binary array
        push(n % 2) ;
        n = n / 2;
    }

    // printing binary array in reverse order
    for (int j = top; j >= 0; j--)
        cout << pop();
}

// Driver program to test above function
int main()
{
    int n = 17;
    decToBinary(n);
    return 0;
}
