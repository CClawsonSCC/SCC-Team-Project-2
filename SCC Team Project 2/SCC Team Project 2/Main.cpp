#include "Parser.h"

#include <iostream>
#include <fstream>

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

		if (line_in_file.size() > 0) // ignores empty lines
		{
			try
			{
				cout << eval_postfix(
					infix_to_postfix(
						read_expression(line_in_file)
					)
				) << endl;
			}
			catch (const std::exception& e)
			{
				cout << "There is a problem with one of the expressions: ";
				cerr << e.what() << endl;
			}
		}
	}

	inputfile.close();

	system("pause");
	return 0;
}