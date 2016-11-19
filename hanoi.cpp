/* 
 * Md. Shafi Ul Alam
 * BSSE- 0630
 * Date: 11-09-2014
 */
/*
 * The program demonstrates the  solution of "Tower Of Hanoi" using the recursion process for N number of disks
 * 
 * pegs denoted by peg-1, peg-2 and peg-3
 * 
 * inputs- N = number of disks
 * 
 * outputs- sample output for 3 disks
 * 			- move disk 1 from peg-1 to peg-3
 * 			- move disk 2 from peg-1 to peg-2
 * 			- move disk 1 from peg-3 to peg-2
 * 			- move disk 3 from peg-1 to peg-3
 * 			- move disk 1 from peg-2 to peg-1
 * 			- move disk 2 from peg-2 to peg-3
 * 			- move disk 1 from peg-1 to peg-3			 
 */
#include <iostream>

using namespace std;

void moveDisks(int numberOfDisks, int peg1, int peg2, int peg3, int& counter);//prototype of the recursive function moveDisks


int main (void)
{
	//take input for the number of disks the user wants to solve
	cout << "Input the number of disks you want to solve: " << endl;
	int numberOfDisks;
	cin >> numberOfDisks;
	
	cout << "\n\n" ;
	
	//set the pegs
	int peg1 = 1;
	int peg2 = 2;
	int peg3 = 3;
	
	int counter = 0; //calculates the total steps requiered
	
	moveDisks (numberOfDisks,peg1,peg2,peg3, counter); //call the recursive function moveDisks at the initial condition
	
	cout << "\n\nNumber of steps: " << counter << endl;
	
	return 0;
}//end main

//body of function moveDisks
void moveDisks(int numberOfDisks, int peg1, int peg2, int peg3 , int& counter) 
{	
	
	if (numberOfDisks > 0) //when there's no disk in peg1
	{
		//use peg3 as the intermediate step and peg2 as final to transfer n-1 disks to peg2
		moveDisks (numberOfDisks - 1, peg1, peg3, peg2, counter);
		
		cout << "move disk " << numberOfDisks << " form " << "peg" << peg1 << " to peg" << peg3 << endl;
		counter++; //increment each time the recursion occurs
	
		//use peg1 as the intermediate step and peg3 as final to transfer all disks to peg3
		moveDisks (numberOfDisks-1, peg2, peg1, peg3, counter);
	}//end if
	
}//end function moveDisks


