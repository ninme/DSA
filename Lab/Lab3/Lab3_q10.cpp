#include<iostream>
using namespace std;
/*void cubeByPtr1 ( int * numPtr ) and void cubeByPtr2 ( int &
numPtr )*/

void cubeByPtr1 ( int * numPtr );
void cubeByPtr2 ( int & numPtr );

int main(){
    int x=3;

    cubeByPtr1(&x);
    cubeByPtr2(x);
}

void cubeByPtr1 ( int * numPtr ){

    cout<<"the cube using pointers= "<<((*numPtr)* (*numPtr) * (*numPtr))<<endl;

}

void cubeByPtr2 ( int &numPtr ){

cout<<"the cube using references= "<<numPtr*numPtr*numPtr<<endl;

}
