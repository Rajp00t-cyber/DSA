#include <iostream>
using namespace std;

int main() 
{
    int arr[5];  
    cout<<"Enter 5 numbers=\n";
    for(int i=0;i<5;i++) 
	{
        cin>>arr[i];
    }
    
    /*
    //if i want to cout an array 
    
    cout<<"Array= ";
    for(int i=0;i<5;i++) 
	{
        cout<<arr[i]<<" ";
    }
    */
    
    int value;
    cout<<"\nEnter the value u want to delete from the array= ";
    cin>>value;

    // if-else-if 
    
    int i=0;
    if (arr[i]==value) 
	{
        for (int j=i;j<4;j++) 
		{
            arr[j]=arr[j+1];
        }
    }
	else
	
	if(arr[1]==value)
	{
        for(int j=1;j<4;j++) 
		{
            arr[j]=arr[j+1];
        }
    } 
	else 
	
	if(arr[2]==value)
	{
        for(int j=2;j<4;j++)
	    {
            arr[j]=arr[j+1];
        }
    }
	
	else
	
    if(arr[3]==value) 
	{
        for(int j=3;j<4;j++) 
		{
            arr[j]=arr[j+1];
        }
    } 
	
	else
	
	if(arr[4]==value)
	{	
        cout<<"Value given by u isn't in the array.";
    }
    
    //updated arrayt
    
    cout<<"\nUpdated Array is= ";
    for (int i=0;i<4;i++) 
	{
        cout<<arr[i]<<" ";
    }
    return 0;
}
