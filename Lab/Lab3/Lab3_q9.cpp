#include<iostream>
using namespace std;

int countEven(int*, int);

int main(){

    int a[]={1,2,3,4,5,6};
    cout<<"Count of evens in the array is= "<<countEven(a,6);

}

int countEven(int *a, int n){
    int counter=0;

    for (int i=0;i<n;i++){
        if((*(a+i))%2==0)
            counter++;
    }

    return counter;
}
