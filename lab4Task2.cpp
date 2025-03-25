#include<iostream>
using namespace std;

struct Node 
{
    int data;
    Node* next;
};

void insertAtBeginning(Node*& head, int newData)
{
    Node* newNode=new Node();  
    newNode->data=newData;    
    newNode->next=head;        
    head=newNode;
}

void deleteFromEnd(Node*& head) 
{
    if (head==NULL) 
    {
        cout<<"List is already empty"<<endl;
        return;
    }
    if (head->next==NULL) 
    {
    // if only one node is in list
        delete head;
        head=NULL;
        cout<<"Last node deleted"<<endl;
        return;
    }

    //finding last node
    Node* temp=head;
    while (temp->next!=NULL&&temp->next->next!=NULL)
    {
        temp=temp->next;
    }

    //delete
    Node* lastNode = temp->next;
    temp->next = NULL;
    delete lastNode;
}

//cout list
void printList(Node* head) 
{
    if (head==NULL) 
    {
        cout<<"List is empty"<<endl;
        return;
    }

    while(head!=NULL) 
    {
        cout<<head->data<<"->";
        head=head->next;
    }
    cout<<"NULL"<<endl;
}
int main() 
{
    Node* head = NULL;

    insertAtBeginning(head,10);
    insertAtBeginning(head,20);
    insertAtBeginning(head,30);
    insertAtBeginning(head,40);

    printList(head);
  
    deleteFromEnd(head);

    printList(head);

    return 0;
}
