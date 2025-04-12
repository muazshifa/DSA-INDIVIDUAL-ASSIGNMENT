#include<iostream>
using namespace std;
	int main( ){
	int arr[]={10,20,30,40,50};
	int n=sizeof(arr)/sizeof(arr[0]);
	int largest,second;
	largest=second=arr[0];
	for(int i=0;i<n;i++)
	{
		if(arr[i]>largest){
			second=largest;
			largest=arr[i];
		}
	else if(arr[i]>second)
		{
			second=arr[i];
			
		}
	}
	cout<<"the second largest number is:"<<second;
	return 0;
}