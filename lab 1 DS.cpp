#include <iostream>
using namespace std;

int main() {
    int arr[5];
    cout<<"Enter 5 numbers= \n";
    for(int i=0;i<5;i++)
	{
        cin>>arr[i];
    }
    //cout array
    for(int i=0;i<5;i++)
	{
        cout<<arr[i]<<" ";
    }
    int value;
    cout<<"\nEnter a new number to replace the last number in the array= ";
    cin>>value;
    arr[4]=value;
    //cout array
    for (int i=0; i<5;i++)
	{
        cout<<arr[i]<<" ";
    }
    return 0;
}
