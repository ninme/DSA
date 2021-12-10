/*Ethiopian premier league soccer result
Write a C++ program that shows team standing for Ethiopian premier league,
the program should uses singly circular linked list and contains the following
functions
i. A function that enable to add teams and points
ii. A function that enable to edit teams points
iii. A function that shows all standing Here is a sample output */
#include<iostream>
#include<string>
#include<iomanip>
using namespace std;

struct Team{
string teamName;
int points;
Team *next;
Team *prev;
};

Team* head=NULL;
Team* tail=NULL;

// add teams according to their points
//This program doesn't sort teams by name if they have same points
void addTeam(string title,int points)
{
	 // Create new node and populate it with data
    Team *newTeam= new Team;
    newTeam->teamName=title;
    newTeam->points=points;

if(head==NULL){
    newTeam->next=newTeam->prev=newTeam;
    head=tail=newTeam;
}
else{
    Team *temp=head;
	// Searching the item.
	do
	{
		if (points>temp->points)
		{
			newTeam -> next = temp;// Adjusting the links.
			newTeam->prev=temp->prev;
            temp->prev->next=newTeam;
            temp->prev=newTeam;
            if(head->prev->prev==tail)
                head=head->prev;
			return ;
		}
		temp = temp -> next;
	} while (temp != head);
	newTeam->next=tail->next;
	head->prev=newTeam;
	newTeam->prev=tail;
	tail->next=newTeam;
	tail=newTeam;
}
}

void editTeamPoints(string tName){
Team*temp=head;
int points;
if(head==NULL)
    cout<<"No registered team yet. This operation is not allowed\n";
else{
    do{
        if(temp->teamName==tName){
            cout<<"Enter the new points for"<<tName<<'\n';
            cin>>points;
            if(points==temp->points){
                cout<<"You entered same point. Hence, No change to the team's point \n";
                return;
            }
            else{
                int p;
                string n="";
                temp->points=points;
                //if(temp->prev==tail && )
                if(temp->points>temp->prev->points){

                    while(temp->points>temp->prev->points && temp->prev!=tail){

                        n=temp->teamName;
                        p=temp->points;

                        temp->teamName=temp->prev->teamName;
                        temp->points=temp->prev->points;

                        temp->prev->teamName=n;
                        temp->prev->points=p;

                        temp=temp->prev;
                    }

            }
            else if(temp->points<temp->next->points){

                while(temp->points<temp->next->points && temp->next!=head){

                    n=temp->teamName;
                    p=temp->points;

                    temp->teamName=temp->next->teamName;
                    temp->points=temp->next->points;

                    temp->next->teamName=n;
                    temp->next->points=p;

                    temp=temp->next;
                }

        }}}
        temp=temp->next;
    }while(temp!=head);
}
}

void showLeagueTable(){
   struct Team* ptr;
   int Position=1;
   if(head==NULL){
    cout<<"List is empty !!\n";
    return;
   }
   ptr = head;
   cout<<"TeamStanding"<<setw(15)<<"Team"<<"\t\tPoints"<<endl;
   cout<<"**************************************************\n";
   do {

      cout<<Position<<setw(30)<<ptr->teamName<<"\t\t"<<ptr->points<<endl;

      ptr = ptr->next;
      Position++;
   } while(ptr != head);
cout<<endl;
}

int menu()
{
    int c;
    cout<<"*************************************************"<<endl;
    cout<<"W E L C O M E"<<endl;
    cout<<"Premier "<<endl;
    cout<<"*************************************************"<<endl;

    cout<<"1. Register Team."<<endl;
    cout<<"2. Edit team points."<<endl;
    cout<<"3. Show the league table"<<endl;

    cout<<"5. Exit."<<endl;
    cout<<"*************************************************"<<endl;

    cout<<"Enter your choice:";
    cin>>c;
    return c;

}

int main(){
    string teamName;
    int points;
    char choice;
char cont;

    do
    {
        int d=menu();
        switch(d)
        {
            case 1:
                cout<<"Enter Team Name: "<<endl;
                cin>>teamName;
                cout<<"Enter Team Points: "<<endl;
                cin>>points;
                addTeam(teamName,points);
                break;
            case 2:
                cout<<"Enter Team Name: "<<endl;
                cin>>teamName;
                editTeamPoints(teamName);
                break;
            case 3:
                showLeagueTable();
                break;
            case 5:
                cout<<"The program is closing...."<<endl;
                cout<<"Thank you for using our App"<<endl;
                return 0;
                break;

        }
        cout<<"Continue?";
        cin>>cont;
    }while(cont=='y' || cont =='Y');
//addTeam("Bunna FC", 30);
////displayList();
//addTeam("Fasil FC",7);
////displayList();
//addTeam("Addis FC", 25);
//displayList();
//addTeam("Zemero FC", 22);
//displayList();
//editTeamPoints("Addis FC");
//displayList();

}

