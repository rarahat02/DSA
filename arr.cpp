#include<iosteram>
using namespace std;
int main (void)
{
	int arr[10][20];
	int **arr;
	arr = new int *[10];
	for(int i = 0; i<10; i++)
	{
	        arr[i] = new int[20];
	}
	for(int i=0; i<10; i++)
	{
	        delete []arr[i];
	}
	delete []arr; 
	return 0;
	
}
