#include<iostream>
using namespace std;

struct Node 
{
    int data;
    Node* next;
};
void insertAtBeginning(Node*& head,int newData)
{
    Node* newNode=new Node();  
    newNode->data=newData;    
    newNode->next=head;        
    head=newNode;
}

//1st node delete
void deleteFromBeginning(Node*& head) 
{
    if(head==NULL)
	{
        cout<<"List is already empty"<<endl;
        return;
    }
    Node* temp = head;
    head=head->next;
    delete temp;
    cout<<"Node deleted"<<endl;
}

//list print
void printList(Node* head) 
{
    if (head==NULL) 
	{
        cout<<"List is empty"<<endl;
        return;
    }
    while (head!=NULL) 
	{
        cout<<head->data<<" -> ";
        head=head->next;
    }
    cout<<"NULL"<<endl;
}

int main() 
{
    Node* head = NULL;
  
  
    insertAtBeginning(head, 10);
    insertAtBeginning(head, 20);
    insertAtBeginning(head, 30);
    insertAtBeginning(head, 40);

    printList(head);
 
    deleteFromBeginning(head);

    printList(head);

    return 0;
}
