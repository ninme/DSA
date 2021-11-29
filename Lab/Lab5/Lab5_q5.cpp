#include <iostream>

using namespace std;

struct login
{
    int loginId;
    string username;
    string password;
    login * next;
}*head=NULL;

void newLoginProfile()
{
    login *newLogin=new login;
    cout<<"NEW LOGIN PROFILE IS CREATING..."<<endl;
    cout<<"Enter user login Id :";
    cin>>newLogin->loginId;
     cout<<"Enter user username:";
    cin>>newLogin->username;
     cout<<"Enter user password :";
    cin>>newLogin->password;
    if(head==NULL)
    {
        newLogin->next=NULL;
        head=newLogin;
    }
    else{
        newLogin->next=head;
        head=newLogin;
    }

}


void deleteLoginProfile()
{
    int d;
    cout<<"Enter login Id to be deleted:";
    cin>>d;

    if(head==NULL)
    {
        cout<<"Deletion is not possible";
        return ;
    }

        login *temp1=head;
        login *temp2;
        //Search the list
    while(temp1->next !=NULL && temp1->loginId !=d){
        temp2=temp1;
        temp1=temp1->next;
    }

    if(temp1->loginId==d){

        if(temp1==head) //Check if the node is the first node and move head pointer to the next book
            head=head->next;
        else
            temp2->next=temp1->next;

        delete temp1;
        cout<<"\n A user with id= "<<d<<" is deleted successfully \n";
        return;
    }
    else
        cout<<"\nThere is no a user with login id "<<d<<endl;

    }


void searchLoginProfile()
{
    int check=0;
    int d;
    cout<<"Enter login Id to be search:";
    cin>>d;
    login *temp=head;
    while(temp!=NULL)
    {
        if(temp->loginId==d)
        {
            check=1;
            cout<<"Login ID:"<<temp->loginId<<endl;
            cout<<"Username:"<<temp->username<<endl;
            cout<<"Password:"<<temp->password<<endl;
            cout<<"________________________________"<<endl;
        }
        temp=temp->next;
    }
    if(check==0)
    {
        cout<<"The data is not found, try again!";
    }
}
void viewLoginProfile()
{
    login *temp=head;
    while(temp!=NULL)
    {
        cout<<"Login ID:"<<temp->loginId<<endl;
        cout<<"Username:"<<temp->username<<endl;
        cout<<"Password:"<<temp->password<<endl;
        cout<<"________________________________"<<endl;
        temp=temp->next;
    }
}

int menu()
{
    int c;
    cout<<"*************************************************"<<endl;
    cout<<"W E L C O M E"<<endl;
    cout<<"LOGIN PROFILE MANAGEMENT SYSTEM"<<endl;
    cout<<"*************************************************"<<endl;

    cout<<"1. New login profile."<<endl;
    cout<<"2. Delete login profile."<<endl;
    cout<<"3. Search login profile."<<endl;
    cout<<"4. Get login profile."<<endl;
    cout<<"5. Exit."<<endl;
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
        switch(d)
        {
            case 1:
                newLoginProfile();
                break;
            case 2:
                deleteLoginProfile();
                break;
            case 3:
                searchLoginProfile();
                break;
            case 4:
                viewLoginProfile();
                break;

        }

        cout<<"Continue?";
        cin>>cont;
    }while(cont=='y' || cont =='Y');
    return 0;
}
