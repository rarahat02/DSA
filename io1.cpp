#include<iostream>
#include<string>
#include<sstream>
#include<iomanip>

using namespace std;

int main (void)
{
/*	int n;
	cin >> n;
	
	string hudai;
	getline(cin, hudai);
	
	for(int i=0; i<n; i++)
	{
		string s;
		getline(cin,s);
		cout << s << endl;
	}
*/
/*
	int n;
	while(cin >> n)
	{
		cout << n << endl;
	}
*/
/*
	g
	
	
	
int n;
	cin >> n;
	while(!cin.eof())
	{
		cout << n << endl;
		cin >> n;
	}
*/	
/*
	int n;
	cin >> n;
	string hudai;
	getline(cin, hudai);
	
	for(int i=0; i<n; i++)
	{
		string s;
		getline(cin, s);	
		
		istringstream iitStream(s);
		
		string word;
		int count =0;
		
		while(iitStream >> word)
		{
			//cout << word << endl;
			count++;
		}
		
		//cout << "Line " << i << " contains " << count  << " words" << endl;
		cout << count << endl;
	}
*/

	int n=77;
	cout << setw(10) << setfill('0') << n << endl;
	
	float f = 123.34543;
	cout << setprecision(6) << f << endl;



	return 0;
}
