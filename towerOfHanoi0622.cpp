#include <iostream>

using namespace std;

void hanoi(int numberOfDisk, int source, int dest, int middle, int &steps)
{
    /*if(numberOfDisk == 0)
	{
		cout << "Move disk " << numberOfDisk << " from tower " << source << " to tower " << dest << endl;
	}*/
	if(numberOfDisk > 0)
	{
		hanoi(numberOfDisk - 1, source, dest, middle, steps);
		
		cout << "Move disk "  << numberOfDisk << " from tower " << source << " to tower " << dest << endl;
		steps ++;

		hanoi(numberOfDisk - 1, middle, source, dest,  steps);
	}
}

int main()
{
 
    int numberOfDisk;
    int steps = 0;
    int source = 1;
    int dest = 3;
    int middle = 2;
    
    cout << "Input the number of disks: " << endl;
    cin >> numberOfDisk;
    cout << endl;
    
    hanoi(numberOfDisk, source, dest, middle, steps);
    
    cout << endl;
    cout << "It took " << steps << " steps to build " << numberOfDisk << " disks." << endl;
  
  return 0;
}
