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
	
	/* this snippit of code reads the whole file word for word.
	while (!inputfile.eof())
	{
		string word;
		inputfile >> word;
		cout << word << endl;
	}
	*/

	// This snippit of code reads a line from the file, and then words from a given line.
	while (!inputfile.eof())
	{
		string line_in_file;
		getline(inputfile, line_in_file);
		
		stringstream ss(line_in_file);

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