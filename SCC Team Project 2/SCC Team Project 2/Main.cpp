#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

int main()
{
	ifstream inputfile("input.txt");
	if (!inputfile.good())
	{
		cout << "File not found!" << endl;
		return -1;
	}

	/*
	* USE THIS:
	* This snippit of code reads a line from the file, and then the words from a given line.
	*/
	while (!inputfile.eof())
	{
		// get the line.
		string line_in_file;
		getline(inputfile, line_in_file);
		
		stringstream ss(line_in_file);

		// output each word.
		while (!ss.eof())
		{
			string word;
			ss >> word;
			cout << word << " ";
		}
		cout << endl;
	}

	inputfile.close();

	system("pause");
	return 0;
}