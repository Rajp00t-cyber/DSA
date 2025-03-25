#include<iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

//  inserting a node at the end of the list
void insertAtEnd(Node*& head, int newData)
{
    Node* newNode=new Node();
    newNode->data=newData;
    newNode->next=NULL;
    
    if (head==NULL) {
        head=newNode;
        return;
    }

    Node* temp=head;
    while (temp->next!=NULL)
    {
        temp=temp->next;
    }
    temp->next=newNode;
}

//now to inserting a node before at specific position we
void insertBeforePosition(Node*& head, int position, int newData)
{
    Node* newNode=new Node();
    newNode->data=newData;

    //head (ie 0)
    if (position==0) 
	{
        newNode->next=head;
        head=newNode;
        return;
    }

    // Traversing the list to find the node just before the target position
    Node* temp=head;
    for (int i=0; i<position-1&&temp!=NULL;++i)
	{
        temp = temp->next;
    }

    // Insert the new node before the given position
    newNode->next=temp->next;
    temp->next=newNode;
}

// print the linked list
void printlist(Node* head)
{
    while (head != NULL) {
        cout << head->data << "->";
        head = head->next;
    }
    cout << "NULL" << endl;
}

int main()
{
    Node* head = NULL;
    
    // Inserting nodes at the end of the list
    insertAtEnd(head, 10);
    insertAtEnd(head, 20);
    insertAtEnd(head, 30);
    insertAtEnd(head, 40);
    
    cout << "list= ";
    printlist(head);
    
    // Inserting 25 before position 2 (i.e., before the node with value 30)
    insertBeforePosition(head, 2, 25);
    
    cout << "After inserting 25 before position 2= ";
    printlist(head);

    
}
