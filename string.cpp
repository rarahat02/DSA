#include<iostream>
#include<string>
#include<cstring>

//>> will stop at space. tab, newline, mismatch and EOF
//<<
//getline will stop at newline
//+
//[]
//length
//at
//celar
//empty
//compare
//copy
//c_str
//substr
//find
//find_first_of
//find_last_of


using namespace std;

int main(void)
{
	string s1,s2, s3;
	getline(cin, s1);
	getline(cin, s2);
	
	int position = s1.find_last_of(s2);
	
	if(s1.find(s2) != string::npos) cout << "found in " << position << endl;
	else cout << "could not find" << endl;

//	s2 = s1.substr(4, 6);
//	cout << s2 << endl;

//	char *buffer = new char[20];
	
//	s1.copy(buffer, 3,3);
//	cout << buffer << endl;
	
//	strcpy(buffer, s1.c_str()) ;
//	cout << buffer << endl;
	
//	delete [] buffer;
	
	//s1.clear();
	//if(s1.empty()) cout << "khali" << endl;
	//else cout << s1.length() << endl;
	
	//getline(cin, s2);
	
//	if(!s1.compare(s2)) cout << "eki kotha" << endl;
//	else cout << "alada" << endl;
/*	
	s3 = s1 + " "s2;
	
	cout << s1 << endl << s2 <<endl;// << s3 << endl;
	
	for(int i=0; i<s1.length(); i++)
	{
		if(s1[i]== ' ') s1[i]='@';
	}
	
		cout << s1<< endl;
	for(int i=0; i<s1.length(); i++)
	{
		cout << s1.at(i) << endl;
	}
*/
	return 0;
}














































