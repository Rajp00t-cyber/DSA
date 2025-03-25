#include<iostream>
using namespace std;

struct Node{
    int data;
    Node* next;
};

void insertAtEnd(Node*& head, int newData)
{
    Node* newNode=new Node();
    newNode->data=newData;
    newNode->next=NULL;
    //condition tells that if the head is empty or null then new node will be inserted immidiately
    if (head==NULL)
	{
        head=newNode;
        return;
    }
//else , it will move to the next , untill finds null then inserts a new node
    Node* temp=head;
    while(temp->next!=NULL) 
	{
        temp=temp->next;
    }
    temp->next=newNode;
}

void printlist(Node* head)
{
    while(head!=NULL)
    {
        cout<<head->data<<"->";
        head=head->next;
    }
    cout<<"NULL"<<endl;
}
int main()
{
    Node* head=NULL;
    
    insertAtEnd(head, 10); 
    insertAtEnd(head, 20); 
    insertAtEnd(head, 30);  
    insertAtEnd(head, 40);  
    
    printlist(head); 
    
}
