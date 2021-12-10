/*Write a program that reads in a sequence of characters and prints them in
reverse order. Use a linked list stack.*/
#include<iostream>
#include<string>
using namespace std;

char mStack[10];
int top=-1;
void push(char c){
if(top<10){
    ++top;
    mStack[top]=c;
}
else
    cout<<"Stack overflow \n";
}

char pop(){
char delValue;
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

int main(){

string chars="abebe kebe";

for(int i=0;i<10;i++)
    push(chars[i]);
for(int j=top;j>=0;j--)
    cout<<pop();

}
