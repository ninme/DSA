/*Lab4 q9. Write three programs in C++ to find out the minimum and maximum value from
the given array using?
A. Insertion sort (2 functions: insertion_max and insertion_min)
B. Selection sort (2 functions: selection_max and selection_min)
C. Bubble sort (2 functions: bubble_max and bubble_min)
Given Array: 6, 5, 3, 1, 8, 7, 2 4*/

#include<iostream>
using namespace std;

int insertion_max(int a[],int n);
int insertion_min(int a[],int n);
int selection_max(int a[],int n);
int selection_min(int a[], int n);
int bubble_max(int a[],int n);
int bubble_min(int a[],int n);

int main(){

int a[]={6, 5, 3, 1, 8, 7, 2, 4};
int i;
const int n=8;
cout<<"Array elements: "<<endl;
for(i=0;i<n;i++){
    cout<<a[i];
    if(i<7)
        cout<<", ";
}
cout<<endl;
cout<<"insertion_max= "<<insertion_max(a,n)<<endl;
cout<<"insertion_min= "<<insertion_min(a,n)<<endl;
cout<<"selection_max= "<<selection_max(a,n)<<endl;
cout<<"selection_min= "<<selection_min(a,n)<<endl;
cout<<"bubble_max= "<<bubble_max(a,n)<<endl;
cout<<"bubble_min= "<<bubble_min(a,n)<<endl;
}

// Returns the maximum element after sorting the elements completely using insertion sort. Complexity: O(n*n)
int insertion_max(int a[],int n){

int temp;
for(int i = 1; i < n; i++){
     temp = a[i];
    for(int j = i; j > 0 && temp < a[j - 1]; j--){ //work backwards through the array finding where temp should go
          a[j] = a[j - 1];
          a[j - 1] = temp;
   }//end of inner loop
  }//end of outer loop
  return a[n-1];
}

// Returns the minimum element after sorting the elements using insertion sort. Complexity: O(n*n)
int insertion_min(int a[],int n){

int temp;
for(int i = 1; i < n; i++){
     temp = a[i];
for(int j = i; j > 0 && temp < a[j - 1]; j--)
{ //work backwards through the array finding where temp should go
          a[j] = a[j - 1];
          a[j - 1] = temp;
   }//end of inner loop
  }//end of outer loop

  return a[0];
}
// Receives the array of n elements and returns the minimum element after one pass sorting using selection sort
int selection_min(int a[], int n){
    int temp; // for swaping

    int minIndex = 0;  // assume fist element is the smallest
    for (int j = 1; j < n; ++j) {
        if (a[j] < a[minIndex])
            minIndex = j;
    }
      if (minIndex != 0) {  // swap
         temp = a[0];
         a[0] = a[minIndex];
         a[minIndex] = temp;
      }
return a[0]; //The minimum is at head of the list after one pass sort
}

// Receives the array of n elements and returns the maximum element after one pass sorting using selection sort.
//Complexity: O(n)
int selection_max(int a[], int n){
    int temp; // for swaping

    int maxIndex = 0;  // assume fist element is the largest
    for (int j = 1; j < n; ++j) {
        if (a[j] > a[maxIndex]) maxIndex = j;
    }
    if (maxIndex != 0) {  // swap
        temp = a[0];
        a[0] = a[maxIndex];
        a[maxIndex] = temp;
      }
return a[0]; //The maximum is at the head of the list after one pass sort
}

//Returns the maximum after one pass sorting using bubble sort. Complexity: O(n)
int bubble_max(int a[],int n){
    int temp;
    for (int i = 0; i < n - 1; ++i) {
        if (a[i] > a[i+1]) {
            temp = a[i];
            a[i] = a[i+1];
            a[i+1] = temp;
         }
   }
return a[n-1]; //The maximum is at end of the list after one pass sort
}

// Returns the minimum value using bubble sort Complexity: O(n)
int bubble_min(int a[],int n){
   int temp;
   for (int i = 0; i < n - 1; ++i) {
         if (a[i] < a[i+1]) { // bubbles the smallest value to the end of the list
            temp = a[i];
            a[i] = a[i+1];
            a[i+1] = temp;
         }
   }

return a[n-1]; //The minimum is at end of the list after one pass sort
}

