#include<iostream>
using namespace std;

/*Write a C++ program to accept five integer values from keyword and print the
elements of the array in reverse order using a pointer.*/

int main(){

const int s=5; //array size
int *a= new int[s]; //dynamic array

//read 5 ints from the keyboard using pointers
cout<<"Enter 5 ints \n";
for(int i=0; i<s;i++)
    cin>>*(a+i);

//Display the ints in reverse order using pointers
cout<<"Numbers in reverse order \n";
for (int i=s-1;i>=0;i--){
    cout<<*(a+i);
    if(i>0)
        cout<<", ";
}
}
