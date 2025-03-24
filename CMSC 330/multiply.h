// Student Name: Dilen Patel
// Date: March 1, 2025
// Project: CMSC 330 Project 2
// Description: Multiplication operator class

#ifndef MULTIPLY_H
#define MULTIPLY_H

#include "subexpression.h"
#include "expression.h"

class Multiply : public SubExpression
{
public:
    Multiply(Expression *left, Expression *right) : SubExpression(left, right)
    {
    }
    double evaluate()
    {
        return left->evaluate() * right->evaluate();
    }
};

#endif