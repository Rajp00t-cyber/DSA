#include<iostream>
using namespace std;

struct Node {
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

void deleteAtPosition(Node*& head,int position) 
{
    if (head==NULL) 
    {
        cout<<"List is empty"<<endl;
        return;
    }

    if (position==0)
    {
        Node* temp=head;
        head=head->next;  
        delete temp;        
        cout<<"Node at position"<<position<<"deleted"<<endl;
        return;
    }

    // traversing is done hre 
    Node* temp=head;
    for (int i=0;temp!=NULL&&i<position-1;i++) 
    {
        temp=temp->next;
    }
    // if given position is greater
    if (temp==NULL||temp->next==NULL)
    {
        cout<<"Position is out of range."<<endl;
        return;
    }
// deleting
    Node* nodeToDelete=temp->next;
    temp->next = temp->next->next;
    delete nodeToDelete;  

    cout<<"Node at position"<<position<<"deleted"<<endl;
}
// cout list
void printList(Node* head) 
{
    if (head==NULL) 
    {
        cout<<"List is empty"<<endl;
        return;
    }
    while (head!=NULL) 
    {
        cout<<head->data<<"->";
        head=head->next;
    }
    cout<<"NULL"<<endl;
}
int main() 
{
    Node* head=NULL;

    insertAtBeginning(head,10);
    insertAtBeginning(head,20);
    insertAtBeginning(head,30);
    insertAtBeginning(head,40);

    printList(head);


    int position;
    cout<<"Enter the position to delete from 1 to 3=";
    cin>>position;

   
    deleteAtPosition(head, position);

    printList(head);

    return 0;
}
