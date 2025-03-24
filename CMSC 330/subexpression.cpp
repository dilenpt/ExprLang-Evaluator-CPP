// Student Name: Dilen Patel
// Date: March 1, 2025
// Project: CMSC 330 Project 2
// Description: Modified to support all operators

#include <iostream>
#include <sstream>
using namespace std;

#include "expression.h"
#include "subexpression.h"
#include "operand.h"
#include "plus.h"
#include "minus.h"
#include "multiply.h"
#include "divide.h"
#include "remainder.h"
#include "exponent.h"
#include "minimum.h"
#include "maximum.h"
#include "average.h"
#include "negation.h"
#include "conditional.h"
#include "extendedconditional.h"

SubExpression::SubExpression(Expression *left, Expression *right)
{
    this->left = left;
    this->right = right;
}

Expression *SubExpression::parse(stringstream &in)
{
    Expression *left;
    Expression *right;
    Expression *third = nullptr;
    Expression *fourth = nullptr;
    char operation, paren;

    left = Operand::parse(in);
    in >> operation;

    // Handle unary operator (postfix)
    if (operation == '~')
    {
        in >> paren;
        return new Negation(left);
    }

    // Handle binary operators
    if (operation == '+' || operation == '-' || operation == '*' || operation == '/' ||
        operation == '%' || operation == '^' || operation == '<' || operation == '>' ||
        operation == '&')
    {
        right = Operand::parse(in);
        in >> paren;

        switch (operation)
        {
        case '+':
            return new Plus(left, right);
        case '-':
            return new Minus(left, right);
        case '*':
            return new Multiply(left, right);
        case '/':
            return new Divide(left, right);
        case '%':
            return new Remainder(left, right);
        case '^':
            return new Exponent(left, right);
        case '<':
            return new Minimum(left, right);
        case '>':
            return new Maximum(left, right);
        case '&':
            return new Average(left, right);
        }
    }

    // Handle ternary operator
    if (operation == '?')
    {
        right = Operand::parse(in);
        third = Operand::parse(in);
        in >> paren;
        return new Conditional(left, right, third);
    }

    // Handle quaternary operator
    if (operation == '#')
    {
        right = Operand::parse(in);
        third = Operand::parse(in);
        fourth = Operand::parse(in);
        in >> paren;
        return new ExtendedConditional(left, right, third, fourth);
    }

    return nullptr;
}