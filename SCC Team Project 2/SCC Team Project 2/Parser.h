#ifndef PARSER_H
#define PARSER_H

#include <stack>
#include <string>
#include <sstream>
#include <algorithm> // used for exponential expressions.


using namespace std;

int eval_postfix(const string& postfix);
int precedence(const string& oper);
string infix_to_postfix(const string& infix_exp);
string read_expression(string expression);

#endif // !PARSER_H
