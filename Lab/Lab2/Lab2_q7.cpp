#include<iostream>
using namespace std;

/*MENU
 1. Add
 2. Subtract
 3. Multiply
 4. Divide
 5. Modulus
Enter your choice: 1
Enter your two numbers: 12 15
Result: 27*/

int add(int,int);
int subtract(int,int);
int mult(int,int);
float divide(int,int);
int mod(int,int);

int* getNumbers(){
int *a=new int[2];
cout<<"Enter the two numbers \n";
cin>>a[0]>>a[1];

return a;
}

int main(){
    char cont;
    int menu;
    int x=10,y=5;
    int *ptr;
    do{
        cout<<"Enter your choice from the given menu"<<endl;
        cout<<"*************************************"<<endl;
        cout<<"1. Add"<<endl;
        cout<<"2. subtract"<<endl;
        cout<<"3. Multiply"<<endl;
        cout<<"4. divide"<<endl;
        cout<<"5. Modulus"<<endl;
        cin>>menu;
        switch(menu){
        case 1:
            ptr=getNumbers();
            cout<<"The sum of the numbers is="<<add(ptr[0],ptr[1])<<endl;
        break;

        case 2:
            ptr=getNumbers();
            cout<<"The difference of the two numbers is= "<<subtract(ptr[0],ptr[1])<<endl;
        break;
        case 3:
            ptr=getNumbers();
            cout<<"The product of the two numbers is= "<<mult(ptr[0],ptr[1])<<endl;
        break;
        case 4:
            ptr=getNumbers();
            cout<<"The quotient of the two numbers is= "<<divide(ptr[0],ptr[1])<<endl;
        break;
        case 5:
            ptr=getNumbers();
            cout<<"The modulus of the two number is= "<<mod(ptr[0],ptr[1])<<endl;
        break;
        default:
            cout<<"You entered wrong option. Pls try again"<<endl;

        }
        cout<<"Enter y to proceed or any other character to quit"<<endl;
        cin>>cont;
    }while(cont=='y' || cont == 'Y');
    cout<<"**********************************"<<endl;
    cout<<"Thank you for using our app..."<<endl;
    cout<<"**********************************"<<endl;
}

int add(int a, int b){
return a+b;
}

int subtract(int a, int b){
return a-b;
}

int mult(int a, int b){
return a*b;
}

float divide(int a, int b){
return a/b;
}

int mod(int a, int b){
return a%b;
}
