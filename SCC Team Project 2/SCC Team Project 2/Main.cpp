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
	
	// rest of code goes here.



	// rest of code ends here.

	inputfile.close();

	system("pause");
	return 0;
}