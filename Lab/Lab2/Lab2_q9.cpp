#include<iostream>
using namespace std;

float avgAge(int age[], int n);
int main(){
    const int size=5;
    int age[]={18,34,44,23,22};
    cout<<"The average age is: "<<avgAge(age, size);

}

float avgAge(int age[], int n){

int sum=0;

for(int i=0; i<n;i++)
    sum+=age[i];

return (sum/(n*1.0));
}
