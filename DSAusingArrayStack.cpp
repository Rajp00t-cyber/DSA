#include <iostream>
#include <string>
using namespace std;

class BookNode 
{
public:
    string title;
    float price;
    string edition;
    int pages;
    //defalt constructor 
    BookNode() 
    {
        title="";
        price=0.0;
        edition="";
        pages=0;
    }
    //perimeter
    BookNode(string t,float p,string e,int pg) 
    {
        title=t;
        price=p;
        edition=e;
        pages=pg;
    }
};
class Stack 
{
private:
    int top;
    int size;
    BookNode arr[5]; 
public:
    //constructor
    Stack() 
    {
        size = 5; 
        top = -1; 
    }
    void push(BookNode book) 
    {
        if(top==size-1)
        {
            cout<<"Stack is full."<<endl;
        } 
        else 
        {
            arr[++top]=book;
            cout<<"Book pushed="<<book.title<<endl;
        }
    }
    BookNode pop() 
    {
        if(top==-1) 
        {
            cout<<"Stack is empty."<<endl;
            return BookNode(); 
        } 
        else 
        {
            return arr[top--];  
        }
    }

    // Peek the top book of the stack
    BookNode peek() 
    {
        if(top==-1) 
        {
            cout<<"Stack is empty."<<endl;
            return BookNode();
        } 
        else 
        {
            return arr[top];  
        }
    }

    void display() 
    {
        if(top==-1)
        {
            cout<<"Stack is empty."<<endl;
        } 
        else 
        {
            cout<<"Books in stack="<<endl;
            for(int i=top;i>=0;--i)
            {
                cout<<"Title="<<arr[i].title<<",Price="<<arr[i].price<<",Edition="<<arr[i].edition<<",Pages="<<arr[i].pages<<endl;
            }
        }
    }
};
int main() 
{
    Stack stack; 
    
    stack.push(BookNode("OOP",90.99,"First Edition",500));
    stack.push(BookNode("DSA",99.00,"Second Edition",300));
    stack.push(BookNode("COAL",93.02,"Third Edition",600));

    stack.display(); 

    BookNode topBook=stack.peek();
    cout<<"Top book="<<topBook.title<<endl;

    BookNode poppedBook=stack.pop();
    cout<<"Popped book="<<poppedBook.title<<endl;

    stack.display();

    return 0;
}
