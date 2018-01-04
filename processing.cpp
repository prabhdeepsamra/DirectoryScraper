#include <string>
#include <iostream>
#include <fstream>
#include <ctype.h>

using namespace std;

int main(){

string line;
bool printout = false;

ifstream input ("testfile.txt");
ofstream output("output.txt");

while(getline(input,line))
{	
	int length = line.length();

	for(int i = 0; i<length;i++)
		{
		if(line[i]=='<')
			{
			printout= false;
			}
		if(line[i]=='>')
			{
			printout= true;
			}
		if(printout && line[i]!= '>' && line[i]!= '['&& line[i]!= ']' && line[i]!= ' ')
			{
			output<<line[i];
			}
		}
	output<<endl;
}

input.close();
output.close();

ifstream input2 ("output.txt");
ofstream output2("fordb.txt");

int linecount = 0;

while(getline(input2,line))
{
	int length = line.length();
	if (length == 0)
		{
		linecount = 0;
		}
	else	
		{
		linecount++;
		
		if (linecount == 1 || linecount == 2)
			{
			for(int i = 0; i<length;i++)
				{
				if(line[i] != '\r')
					{
					output2<<line[i];	
					}
				}
			output2<< ",";
			}

		if (linecount == 3)
			{
			for(int i = 0; i<length;i++)
				{
				if(isupper(line[i]))
					{
					output2<<",";
					}
				output2<<line[i];	
				}
			output2<<endl;
			} 
		}	
}


}
