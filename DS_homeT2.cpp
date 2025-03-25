#include <iostream>
using namespace std;
int main() 
{
	/*
	Defination
	By this kind of increment and decrement
	only array index number being pointed,
	will increase and decrease.
	*/
	
    int arr[]={10, 20, 30, 40, 50};
    int *ptr=arr;
    
    cout<<"Initial Pointer Value="<<*ptr<<endl;
    //increment
    ptr++;
    cout<<"After Increment="<<*ptr<<endl;

    //decrement
    ptr--;
    cout<<"After Decrement= "<<*ptr<<endl;

    //Adding 2
    ptr+=2;
    cout<<"After Adding 2= "<<*ptr<<endl;

    // subtracting 1
    ptr--;
    cout<<"After Subtracting 1="<<*ptr<<endl;

    return 0;
}
