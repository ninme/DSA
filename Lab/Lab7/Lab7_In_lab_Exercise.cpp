#include<iostream>
using namespace std;

/*1. Create an empty doubly linked list called Number containing a data member. */
struct Number{
int data;
Number*next;
Number*prev;
}*head=NULL;

/*Add the following elements at the beginning of the list in order, elements are:
45, 7, 11, 57, 90, 30, 84, 61 */

void addFirst(int value){
//create new node
Number* newNum= new Number;
newNum->data=value;
newNum->prev=NULL;

if(head==NULL){
    head=newNum;
    newNum->next=NULL;
}else{
newNum->next=head;
head->prev=newNum;
head=newNum;
}
}

/*3. Showing the minimum and maximum items */
int minimum(){
    int minimum;
    if(head==NULL)
        return INT_MIN;
    else if(head->next==NULL)
        return head->data;
    else{
        minimum=head->data;
        Number*temp=head->next;
        while(temp!=NULL){
            if(temp->data<minimum)
                minimum=temp->data;
            temp=temp->next;
        }
    }
    return minimum;
}

/*3. Showing the minimum and maximum items */
int maximum(){
    int maximum;
    if(head==NULL)
        return INT_MAX;
    else if(head->next==NULL)
        return head->data;
    else{
        maximum=head->data;
        Number*temp=head->next;
        while(temp!=NULL){
            if(temp->data>maximum)
                maximum=temp->data;
            temp=temp->next;
        }
    }
    return maximum;
}
/*A program to count elements of doubly linked list*/
int Count(){
    int c=0;
    if(head==NULL)
        return c;
    else if(head->next==NULL)
        return 1;
    else{
        Number*temp=head;
        while(temp!=NULL){
            c++;
            temp=temp->next;
        }
    }
    return c;
}

void display(){
Number *temp=head;
if(head==NULL)
    cout<<"The list is empty\n";
else{
        Number *temp=head;
while(temp!=NULL){
    cout<<temp->data;
    if(temp->next!=NULL)
        cout<<"=>";
    temp=temp->next;
}
cout<<endl;

}
}
// Testing
int main()
{
/*Add the following elements at the beginning of the list in order, elements are:
45, 7, 11, 57, 90, 30, 84, 61*/
addFirst(45);
addFirst(7);
addFirst(11);
addFirst(57);
addFirst(90);
addFirst(30);
addFirst(84);
addFirst(61);
//Show items in the list
display();

cout<<"\nThe minimum node: "<<minimum()<<endl;
cout<<"The maximum node: "<<maximum()<<endl;
cout<<"The count of nodes in the list: "<<Count()<<endl;


}
