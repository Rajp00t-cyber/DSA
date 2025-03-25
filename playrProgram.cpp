#include <iostream>
#include <string>

using namespace std;

struct Player {
    string name;
    int score;
    Player* next;
    Player* prev;
};

void addPlayer(Player*& head, string name, int score) {
    Player* newPlayer = new Player{name, score, nullptr, nullptr};

    if (!head) 
	{
        head=newPlayer;
        return;
    }
    Player* current=head;
    while (current) 
	{
        if(current->score > score)
		{
            newPlayer->next = current;
            newPlayer->prev = current->prev;
            if (current->prev)
			{
                current->prev->next=newPlayer;
            } 
			else 
			{
                head=newPlayer; 
            }
            current->prev=newPlayer;
            return;
        }
        if (!current->next)
		 {
            current->next=newPlayer;
            newPlayer->prev=current;
            return;
        }
        current=current->next;
    }
}
void displayAll(Player* head){
    Player* current=head;
    while (current) 
	{
        cout<<current->name<<"="<<current->score<<endl;
        current=current->next;
    }
}
void displayLowestScore(Player* head) 
{
    if (!head) 
	{
        cout<<"No players in the tournament."<<endl;
        return;
    }
    Player* current=head;
    while (current->next) 
	{
        current=current->next;
    }
    cout<<"Player with the lowest score= "<<current->name<<"="<<current->score<<endl;
}
void displaySameScore(Player* head, string name) {
    Player* current=head;
    Player* target=nullptr;
    while (current) 
	{
        if (current->name==name) 
		{
            target=current;
            break;
        }
        current=current->next;
    }

    if (!target)
	{
        cout<<"Player not found."<<endl;
        return;
    }
    current=head;
    cout<<"Players with the same score as "<<name<<" ("<<target->score<<"):"<<endl;
    while (current) 
	{
        if (current->score==target->score) 
		{
            cout<<current->name<<"="<<current->score<<endl;
        }
        current=current->next;
    }
}
void displayBackwardFromPlayer(Player* head, string name) {
    Player* current=head;
    while(current) 
	{
        if(current->name==name) 
		{
            break;
        }
        current=current->next;
    }
    if (!current) 
	{
        cout<<"Player not found."<<endl;
        return;
    }
    cout<<"Players behind "<<name<<"="<<endl;
    while(current->prev) 
	{
        current=current->prev;
        cout<<current->name<<"="<<current->score<<endl;
    }
}
void freeMemory(Player* head) 
{
    Player* current=head;
    while (current) 
	{
        Player* next=current->next;
        delete current;
        current=next;
    }
}
int main() {
    Player* head=nullptr;
    int choice;
    string name;
    int score;
    do 
	{
        cout<<"\n1. Add Player\n2. Display All Players\n3. Display Lowest Score\n4. Display Same Score\n5. Display Backward From Player\n6. Exit\n";
        cout<<"Enter your choice: ";
        cin>>choice;

        switch (choice) 
		{
            case 1:
                cout<<"Enter player name=";
                cin>>name;
                cout<<"Enter player score= ";
                cin>>score;
                addPlayer(head, name, score);
                break;
            case 2:
                displayAll(head);
                break;
            case 3:
                displayLowestScore(head);
                break;
            case 4:
                cout<<"Enter player name to find same score= ";
                cin>>name;
                displaySameScore(head, name);
                break; 
            case 5:
                cout<<"Enter player name to display backward= ";
                cin>>name;
                displayBackwardFromPlayer(head, name);
                break;
            case 6:
                cout<<"Exiting the program."<<endl;
                break;
            default:
                cout<<"Invalid choice. Please try again."<<endl;
        }
    } 
	while(choice != 6);

    freeMemory(head);
    return 0;
}