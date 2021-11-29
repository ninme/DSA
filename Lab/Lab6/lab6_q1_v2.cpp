/*Write a C++ program to implement library management system, which helps to
maintain a book-list in a small library. The book information contains the title,
author, publish year, and ISBN code. It provides functions to: - add a book - delete
a book based on the ISBN code or title - search for a book based on the ISBN code
- list all books - It also provides an easy way for users to select a command from a
command menu to perform the above functions and to input data from the
keyboard.*/
#include<iostream>
#include<string>
#include<iomanip>
using namespace std;

struct Book{
string title;
string author;
int publishYear;
int isbn;
Book *next;
};

Book *head=NULL;

void addBook();
void deleteBook(int isbn);
Book* search(int isbn);
void listBooks();
int menu()
{
    int c;
    cout<<"*************************************************"<<endl;
    cout<<"W E L C O M E"<<endl;
    cout<<"LIBRARY MANAGEMENT SYSTEM"<<endl;
    cout<<"*************************************************"<<endl;

    cout<<"1. Add new book."<<endl;
    cout<<"2. List books in the library."<<endl;
    cout<<"3. Delete Book from the library."<<endl;
    cout<<"4. Exit"<<endl;
    cout<<"*************************************************"<<endl;

    cout<<"Enter your choice:";
    cin>>c;
    return c;

}

int main()
{
    char cont;

    do
    {
        int d=menu();
        int isbn=INT_MIN;
        switch(d)
        {
            case 1:
                addBook();
                break;
            case 2:
                listBooks();
                break;
            case 3:
                cout<<"Enter the isbn of the book you want to delete\n";
                cin>>isbn;
                deleteBook(isbn);
                break;
            case 4:
                cout<<"\n The app is terminating ...\n";
                cout<<"Thank you for using the APP\n";
                return 0;
                break;
        }

        cout<<"Do you want to continue?\n";
        cout<<"Please enter \'y\' or \'Y\' to continue or any other character otherwise\n";
        cin>>cont;
    }while(cont=='y' || cont =='Y');
    return 0;
}


// Add the new books to from of the list
void addBook(){
Book *newBook= new Book;
cout<<"\n ****Enter Book details: **** \n";
cout<<"Enter isbn: ";cin>>newBook->isbn;
cout<<"Enter title: ";cin>>newBook->title;
cout<<"Enter Author: ";cin>>newBook->author;
cout<<"Enter year of publication: ";cin>>newBook->publishYear;

if(head==NULL){
    head=newBook;
    newBook->next=NULL;
}
else{
    newBook->next=head;
    head=newBook;
}
}

//deletes book based on the isbn information
void deleteBook(int isbn){
Book *temp1, *temp2;
temp1=head;
temp2=NULL;

if(head==NULL){
    cout<<"List is empty. Deletion is not possible \n";
}
//Search the list
while(temp1->next !=NULL && temp1->isbn !=isbn){
    temp2=temp1;
    temp1=temp1->next;
}

if(temp1->isbn==isbn){

        if(temp1==head) //Check if the node is the first node and move head pointer to the next book
            head=head->next;
        else
            temp2->next=temp1->next;

    delete temp1;
    cout<<"\n A book with ISBN= "<<isbn<<" is deleted successfully \n";
    return;
}
else
    cout<<"\nThere is no book with isbn "<<isbn<<endl;

}

void listBooks(){
Book *temp=head;
cout<<"\n*****List of books in the library *****\n ";
    cout<<setw(6)<<"ISBN: ";
    cout<<setw(15)<<"Title: ";
    cout<<setw(15)<<"Author: ";
    cout<<setw(15)<<"Year: "<<endl;
while(temp!=NULL){
    cout<<setfill(' ')<<setw(6)<<temp->isbn;
    cout<<setfill(' ')<<setw(15)<<temp->title;
    cout<<setfill(' ')<<setw(15)<<temp->author;
    cout<<setfill(' ')<<setw(15)<<temp->publishYear<<endl;
        temp=temp->next;
}
}
