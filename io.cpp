#include<iostream>
#include<string>

using namespace std;

int main (void)
{
	string name;
	int age;
	
	cout << "Please enter name and age: ";
	getline(cin, name);
	cin >> age;
	cout << "The person " << name << " is aged " << age << endl;		
	return 0;
}
