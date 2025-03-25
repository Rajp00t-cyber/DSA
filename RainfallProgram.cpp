#include <iostream>
using namespace std;

struct Node {
    float rainfall;  
    Node* prev;      
    Node* next;      

    Node(float value) 
	{
        rainfall=value;
        prev=nullptr;
        next=nullptr;
    }
};
void addToEnd(Node*& head, float value) 
{
    Node* newNode=new Node(value);
    if (head==nullptr)
	{
        head=newNode; 
    } 
	else 
	{
        Node* temp=head;
        while (temp->next!=nullptr)
		{
            temp=temp->next;
        }
        temp->next=newNode; 
        newNode->prev=temp; 
    }
}
void createList(Node*& head) 
{
    float value;
    
    cout<<"Enter rainfall for 7 days (in mm)="<<endl;
    
    for (int i=1;i<=7;i++) 
	{
        do {
            cout<<"Day"<<i<<"=";
            cin>>value;
            if (value<0) 
			{
                cout<<"Invalid input.Rainfall cannot be negative."<<endl;
            }
        } 
		while (value<0);

        addToEnd(head, value);
    }
}
float totalRainfall(Node* head) 
{
    float total=0;
    Node* current=head;
    while (current!=nullptr) 
	{
        total+=current->rainfall; 
        current=current->next; 
    }
    return total;
}
float averageRainfall(Node* head) 
{
    return totalRainfall(head)/7;
}
void highestAndLowestRainfall(Node* head) 
{
    if (head==nullptr) {
        cout<<"List is empty!"<<endl;
        return;
    }

    Node* current=head;
    Node* highest=head;
    Node* lowest=head;

    while (current != nullptr) 
	{
        if (current->rainfall>highest->rainfall)
		{
            highest=current; 
        }
        if (current->rainfall<lowest->rainfall) 
		{
            lowest=current;
        }
        current=current->next; 
    }
    cout<<"Day with the highest rainfall="<<highest->rainfall<<"mm."<<endl;
    cout<<"Day with the lowest rainfall="<<lowest->rainfall<<"mm."<<endl;
}
void rainfallAfter5thNode(Node* head) {
    Node* current = head;
    int count=1;

    while (current!=nullptr&&count<5)
	{
        current=current->next; 
        count++;
    }

    if (current!=nullptr&&current->next!=nullptr) 
	{
        cout<<"Rainfall on the day after the 5th node="<<current->next->rainfall<<"mm."<<endl;
    } 
	
	else 
	{
        cout<<"There is no day after the 5th node."<<endl;
    }
}
void printList(Node* head) 
{
    Node* current=head;
    cout<<"Rainfall data for the week=";
    while (current!=nullptr) 
	{
        cout<<current->rainfall<<" ";
        current=current->next; 
    }
    cout<<endl;
}
void freeMemory(Node* head) 
{
    Node* current=head;
    while (current!=nullptr) 
	{
        Node* next=current->next;
        delete current; 
        current=next; 
    }
}
int main() 
{
    Node* head=nullptr; 

    createList(head);

    printList(head);
    cout<<"Total rainfall for the week="<<totalRainfall(head)<<"mm."<<endl;
    cout<<"Average weekly rainfall= "<<averageRainfall(head)<<"mm."<<endl;

    highestAndLowestRainfall(head);

    rainfallAfter5thNode(head);

    freeMemory(head);
    
    return 0;
}