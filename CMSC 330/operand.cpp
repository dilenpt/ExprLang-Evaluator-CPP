// Student Name: YOUR NAME
// Date: March 1, 2025
// Project: CMSC 330 Project 2
// Description: Modified to support floating-point literals

#include <cctype>
#include <iostream>
#include <sstream>
#include <list>
#include <string>
using namespace std;

#include "expression.h"
#include "subexpression.h"
#include "operand.h"
#include "variable.h"
#include "literal.h"
#include "parse.h"

Expression *Operand::parse(stringstream &in)
{
    char paren;
    double value;

    in >> ws;
    if (isdigit(in.peek()) || in.peek() == '.')
    {
        in >> value;
        Expression *literal = new Literal(value);
        return literal;
    }
    if (in.peek() == '(')
    {
        in >> paren;
        return SubExpression::parse(in);
    }
    else
        return new Variable(parseName(in));
    return 0;
}