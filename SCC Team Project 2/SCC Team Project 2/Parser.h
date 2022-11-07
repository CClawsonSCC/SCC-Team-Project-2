#ifndef PARSER_H
#define PARSER_H

#include<stack>
#include<string>
#include <sstream>
#include<math.h>


using namespace std;

/** Evaluates a postfix expression.
    @param postfix: postfix expression to evaluate
    @return: evaluation result
    @throws exception: divide-by-zero
*/
int eval_postfix(const string& postfix) {
    istringstream iss(postfix);
    stack<int> stk;
    string token;  // Current token
    while (iss >> token) {
        if (isdigit(token.front())) { stk.push(stoi(token)); }
        else {
            int right = stk.top();
            stk.pop();
            int left = stk.top();
            stk.pop();

            // Supported operators
            if (token == "^") { stk.push(pow(left, right)); }
            if (token == "*") { stk.push(left * right); }
            if (token == "/") {
                if (!right) { throw exception("Divide by zero"); }
                stk.push(left / right);
            }
            if (token == "%") { stk.push(left % right); }
            if (token == "+") { stk.push(left + right); }
            if (token == "-") { stk.push(left - right); }
            if (token == ">") {
                if (left > right) {
                    stk.push(1);
                }
                else { stk.push(0); }
            }
            if (token == ">=") {
                if (left >= right) {
                    stk.push(1);
                }
                else { stk.push(0); }
            }
            if (token == "<") {
                if (left < right) {
                    stk.push(1);
                }
                else { stk.push(0); }
            }
            if (token == "<=") {
                if (left <= right) {
                    stk.push(1);
                }
                else { stk.push(0); }
            }
            if (token == "==") {
                if (left == right) {
                    stk.push(1);
                }
                else { stk.push(0); }
            }
            if (token == "!=") {
                if (left != right) {
                    stk.push(1);
                }
                else { stk.push(0); }
            }
            if (token == "&&") {
                if (left != 0 && right != 0) {
                    stk.push(1);
                }
                else { stk.push(0); }
            }
            if (token == "||") {
                if (left == 0 && right == 0) {
                    stk.push(0);
                }
                else { stk.push(1); }
            }
        }
    }
    return stk.top();
}  // Time complexity: O(n)

/** Returns the precedence of an operator.
    @param oper: operator to return its precedence
    @return: precedence
    @throws exception: operator unsupported
*/
int precedence(const string& oper) {
    if (oper == "^") { return 1; }
    if (oper == "*" || oper == "/" || oper == "%") { return 5; }
    if (oper == "+" || oper == "-") { return 6; }
    if (oper == ">" || oper == ">=" || oper == "<" || oper == "<=") { return 9; }
    if (oper == "=" || oper == "!=") { return 10; }
    if (oper == "&&") { return 14; }
    if (oper == "||") { return 15; }
    throw exception("Unsupported operator");
}  // Time complexity: O(1)

/** Converts an infix expression to postfix expression.
    @param infix_exp: infix expression to convert
    @return: postfix expression converted from the infix expression
*/
string infix_to_postfix(const string& infix_exp) {
    istringstream iss(infix_exp);
    ostringstream oss;
    stack<string> stk;
    string token;
    while (iss >> token) {
        if (isdigit(token.front())) { oss << ' ' << token; }
        else if (token == "(") { stk.push(token); }
        else if (token == ")") {
            while (stk.top() != "(") {
                oss << ' ' << stk.top();
                stk.pop();
            }
            stk.pop();
        }
        else {
            while (!stk.empty() && stk.top() != "(" && precedence(token) >= precedence(stk.top())) {
                oss << ' ' << stk.top();
                stk.pop();
            }
            stk.push(token);
        }
    }
    while (!stk.empty()) {
        oss << ' ' << stk.top();
        stk.pop();
    }
    return oss.str();
}  // Time complexity: O(n)

#endif // !PARSER_H

