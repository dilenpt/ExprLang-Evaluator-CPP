// Student Name: Dilen Patel
// Date: March 1, 2025
// Project: CMSC 330 Project 2
// Description: Minimum operator class

#include "subexpression.h"
#include "expression.h"

#ifndef MINIMUM_H
#define MINIMUM_H

class Minimum : public SubExpression
{
public:
    Minimum(Expression *left, Expression *right) : SubExpression(left, right)
    {
    }
    double evaluate()
    {
        double leftVal = left->evaluate();
        double rightVal = right->evaluate();
        return (leftVal < rightVal) ? leftVal : rightVal;
    }
};

#endif