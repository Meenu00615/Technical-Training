/*Experiment 1: Reversing array in C++*/
#include<iostream> 
using namespace std; 

/*pointer start and end*/
void rvereseArray(int arr[], int start, int end) 
{ 
	while (start < end) 
	{ 
		int temp = arr[start]; 
		arr[start] = arr[end]; 
		arr[end] = temp; 
		start++; 
		end--; 
	} 
}	 

/*print array function*/
void printArray(int arr[], int size) 
{ 
for (int i = 0; i < size; i++) 
cout << arr[i] << " "; 

cout << endl; 
} 

int main() 
{ 
	int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10}; 
	
	int n = sizeof(arr) / sizeof(arr[0]); 

	//original array 
	printArray(arr, n); 
	
	//calling  the function
	rvereseArray(arr, 0, n-1); 
	
	cout << "Reversed array is" << endl; 
	
	//print Reversed array 
	printArray(arr, n); 
	
	return 0; 
} 
