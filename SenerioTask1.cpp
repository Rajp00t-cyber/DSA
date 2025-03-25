#include <iostream>
using namespace std;

//dble link list
struct Node {
    int data;       
    Node* prev;     
    Node* next;     
    Node(int val) 
	{
        data=val;
        prev=nullptr;
        next=nullptr;
    }
};
void addToBeginning(Node*& head, int value) 
{
    Node* newNode=new Node(value);
    if (head==nullptr) 
	{
        head=newNode;
    } 
	else
	{
        newNode->next=head; 
        head->prev=newNode; 
        head = newNode;        
    }
}

void addAfter45(Node* head, int value) {
    Node* current=head;
    while (current!=nullptr) 
	{
        if (current->data==45) 
		{
            Node* newNode=new Node(value);
            newNode->next=current->next;
            newNode->prev=current;       
            
            if (current->next!=nullptr) 
			{
                current->next->prev=newNode; 
            }
            current->next=newNode; 
            cout<<"Node with value "<<value<<" added after node with value 45."<<endl;
            return;
        }
        current=current->next;
    }
    cout<<"Node with value 45 not found."<<endl;
}
void printList(Node* head) {
    Node* current=head;
    while (current!=nullptr) 
	{
        cout<<current->data<<" "; 
        current=current->next;       
    }
    cout<<endl;
}

void createList(Node*& head, int n) {
    int value;
    cout<<"Enter "<<n<<" marks="<<endl;
    
    for (int i=0;i<n;i++)
	{
        cin>>value; 
        addToBeginning(head, value);
    }
}

int main() {
    int n, value;
    Node* head=nullptr;

    cout<<"Enter the number of nodes= ";
    cin>>n;

    createList(head, n);

    cout<<"Initial list= ";
    printList(head);

    cout<<"Enter value to add at the bigining= ";
    cin >> value;
    addToBeginning(head, value);
    cout<<"List after adding to the biginning= ";
    printList(head); 

    cout<<"Enter value to add after 45=";
    cin>>value;
    addAfter45(head, value);
    cout<<"List after adding after 45=";
    printList(head); 

    return 0;
}