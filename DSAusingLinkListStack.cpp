/*

                 Rida Eman
                 59510

*/
#include <iostream>
#include <string>
using namespace std;

class Inventory {
public:
    int serialNum;
    int manufactYear;
    int lotNum;
    Inventory() 
	{
        serialNum=0;
        manufactYear=0;
        lotNum=0;
    }
    Inventory(int sNum,int mYear,int lNum)
	 {
        serialNum=sNum;
        manufactYear=mYear;
        lotNum=lNum;
    }
    void display() 
	{
        cout<<"Serial Number="<<serialNum<<",Manufacturing Year="<<manufactYear<<",Lot Number="<<lotNum<<endl;
    }
};
class Node 
{
public:
    Inventory data;
    Node* next;
    Node(Inventory inv) 
	{
        data=inv;
        next=nullptr;
    }
};

class Stack 
{
private:
    Node* top;
public:
    Stack() 
	{
        top=nullptr;
    }
    void push(Inventory inv) 
	{
        Node* newNode=new Node(inv);
        newNode->next=top;
        top=newNode;
        cout<<"Part added to inventory."<<endl;
    }
    Inventory pop() 
	{
        if(top==nullptr) 
		{
            cout<<"Stack is empty."<<endl;
            return Inventory();
        }
		else 
		{
            Node* temp=top;
            Inventory inv=top->data;
            top=top->next;
            delete temp;
            return inv;
        }
    }
    void display() 
	{
        if(top==nullptr) 
		{
            cout<<"Stack is empty."<<endl;
        } 
		else 
		{
            cout<<"Current Inventory="<<endl;
            Node* current=top;
            while(current!=nullptr) 
			{
                current->data.display();
                current=current->next;
            }
        }
    }
    ~Stack() {
        while (top!=nullptr) 
		{
            pop();
        }
    }
};

int main() 
{
    Stack stack;
    char choice;
    do 
	{
        cout<<"To add a part to inventory enter 'a' and to take a part from inventory enter 't' and 'q' to quit= ";
        cin>>choice;
        if(choice == 'a')
		{
            int serialNum,manufactYear,lotNum;
            
            cout<<"Enter Serial Number=";
            cin>>serialNum;
            cout<<"Enter Manufacturing Year=";
            cin>>manufactYear;
            cout<<"Enter Lot Number=";
            cin>>lotNum;
            Inventory inv(serialNum,manufactYear,lotNum);
            
            stack.push(inv);
            
        } 
		else 
		if(choice=='t') 
		{
            Inventory inv=stack.pop();
            if(inv.serialNum!=0) 
			{
                cout<<"Removed Part Details";
                inv.display();
            }
        }
    } while(choice!='q');
    
    stack.display();
    return 0;
}