#pragma once

#include <string>
#include <sstream> // useful for picking apart words in a string.
#include <stack>

class Parser
{
public:
private:
	// Data fields
	std::string infix_str;
	std::stack<int> values;
	std::stack<std::string> operands;

	int result_val = 0;
};