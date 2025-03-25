#include<iostream>
using namespace std;

struct Node{
	int data;
	Node* next;
};
    void insertAtBigning(Node*& head, int newData)
	{
		Node* newNode=new Node();
		newNode->data=newData;
        newNode->next=head;
        head=newNode;
	}
	
	void printlist(Node* head)
	{
		while(head!=NULL){
		cout<<head->data<<"->";
		head=head->next;
	}
	cout<<"NULL"<<endl;
	}
	
int main()
{
    Node* head= NULL;
    
    insertAtBigning(head, 10);
    insertAtBigning(head, 20);
    insertAtBigning(head, 30);
    insertAtBigning(head, 40);
    
    printlist(head);
}