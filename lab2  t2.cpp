#include<iostream>
using namespace std;

int main()
{
    int a=50;
    int b=60;
    
    int *ptr1=&a;
    int *ptr2=&b;
    
    int **q1=&ptr1;
    int **q2=&ptr2;
    
    cout<<**q1<<endl;
    
    cout<<**q2;

    return 0;
}
