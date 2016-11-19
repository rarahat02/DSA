#include<iostream>

using namespace std;

int main()
{
    int sizeOfArray;
    cin >> sizeOfArray;
    
    int arrayOfNumbers[sizeOfArray];
    
    for(int i=0; i<sizeOfArray; i++)
    {
        cin >> arrayOfNumbers[i];
    }
    cout << endl;
    /*for(int i=0; i<sizeOfArray; i++)
    {
        cout << arrayOfNumbers[i] << endl;
    }*/
    
    int bigNum = 0;
    int smallNum= 0;
    
    for(int i=0; i<sizeOfArray ;i++)
    {
        int currentNum = arrayOfNumbers[i];
        int nextNum = arrayOfNumbers[i+1];;
        if(currentNum > nextNum)
        {
            bigNum = currentNum;
            smallNum = nextNum;
            arrayOfNumbers[i] = smallNum;
            arrayOfNumbers[i+1] = bigNum;
        }
        else
        {
           
        }
    }
    for(int i=0; i<sizeOfArray; i++)
    {
        cout << arrayOfNumbers[i] << endl;
    }
}
