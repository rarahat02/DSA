#include<iostream>
#include<string>
#include<stack>
#include<vector>
#include<sstream>

using namespace std;

struct content
{
    float number;
    char symbol;
    bool flag;
};

char symbols[6] = {'+','-','*','/','(',')'};
void replaceSymbol(string &numbers)
{
    for(int i=0; i<6; i++)
    {
        for(int j=0; j<numbers.length(); j++)
        {
            if(symbols[i]==numbers[j])
            {
                numbers[j]=' ';
            }
        }
    }
}

void makeContentWithSymbols(content &node,char symbolFromInputString)
{
    node.symbol = symbolFromInputString;
    node.flag = false;
}

void makeContentWithNumbers(content &node,float numberObtained)
{
    node.number = numberObtained;
    node.flag = true;
}

void persingInput(string inputString,vector <content> &infix)
{
    string numbers = inputString;

    replaceSymbol(numbers);

    istringstream iss(numbers);

    vector <float> numbersObtained;
    float temp;
    while(iss >> temp)
    {
        numbersObtained.push_back(temp);
    }

    for(int i=0; i<numbers.size(); i++)//number.size keno?
    {
        if(numbers[i]==' ') //ekhane == hobe kintu tui = disili -_-
        {
            if(i!=0)
            {
                if(numbers[i-1]!=' ')
                {
                    content node;
                    makeContentWithNumbers(node,numbersObtained[0]);
                    infix.push_back(node);
                    numbersObtained.erase(numbersObtained.begin());

                    makeContentWithSymbols(node,inputString[i]);
                    infix.push_back(node);
                }
                else
                {
                    content node;
                    makeContentWithSymbols(node,inputString[i]);
                    infix.push_back(node);
                }
            }
            else
            {
                content node;
                makeContentWithSymbols(node,inputString[i]);
                infix.push_back(node);
            }
        }

    }
    if(!numbersObtained.empty())
	{
		content node;
		makeContentWithNumbers(node, numbersObtained[0]);
		infix.push_back(node);
		numbersObtained.erase(numbersObtained.begin());
	}
}

int main()
{
    string inputString;
    getline(cin,inputString);

    vector <content> infix;
    persingInput(inputString,infix);

    for(int i=0; i<infix.size(); i++)
    {
        if(!infix[i].flag) cout << infix[i].symbol; //else ta aikhane extra 12 print kore ditese bt keno?r shudhu symbol print korleo keno purata dekhaitese????
        else cout << infix[i].number;
    }

    /*vector <content> prefix;
    infixToPrefix(infix,prefix);  */
}
