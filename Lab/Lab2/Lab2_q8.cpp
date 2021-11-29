#include<iostream>
using namespace std;

/*Write a program that will ask the user to input three integer values from the
keyboard. Then it will print the smallest and largest of those numbers */
void maxMin(int a[], int size){

int first, second, third;

first=second=third=INT_MIN;
for(int i=0; i<size; i++){

    if(a[i]>first){
        third=second;
        second=first;
        first=a[i];
    }
    else if(a[i]> second){
        third=second;
        second= a[i];
    }
    else if(a[i]> third)
        third=a[i];
}

cout<<"\nThe largest is: "<<first<<endl;
cout<<"The smallest is: "<<third<<endl;

}


int main(){

int a[3];

cout<<"Enter three integers from keyboard "<<endl;
for (int i=0; i<sizeof(a)/sizeof(int); i++)
    cin>>a[i];

cout<<"*****The three ins are: ****"<<endl;
for (int i=0; i<sizeof(a)/sizeof(int); i++)
{
    cout<<a[i];
    if(i<2)
        cout<<", ";
    else
        cout<<endl;
}


maxMin(a,sizeof(a)/sizeof(int) );

}
