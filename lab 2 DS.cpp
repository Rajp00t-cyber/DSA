#include<iostream>
using namespace std;

int main()
{
    int a=5;
    int *ptr=NULL;

    if (ptr==NULL)
    {
        cout<<"The pointer is Null\n";
        ptr = &a; 
        
        int Int = 10;
        float Float = 5.7;
        char Char = 'c';
        double Double = 9000;
        
        void *ptr2=&Int;
        void *ptr3=&Float;
        void *ptr4=&Char;
        void *ptr5=&Double;

        cout<<*ptr<<endl;
        cout<<*(int*)ptr2<<endl;
        cout<<*(float*)ptr3<<endl;
        cout<<*(char*)ptr4<<endl;
        cout<<*(double*)ptr5<<endl;
    }
    else
    {
        cout<<"The pointer is not null!";
    }

    return 0;
}
