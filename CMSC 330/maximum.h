// Student Name: Dilen Patel
// Date: March 1, 2025
// Project: CMSC 330 Project 2
// Description: Maximum operator class

#ifndef MAXIMUM_H
#define MAXIMUM_H

#include "subexpression.h"
#include "expression.h"

class Maximum : public SubExpression
{
public:
    Maximum(Expression *left, Expression *right) : SubExpression(left, right)
    {
    }
    double evaluate()
    {
        double leftVal = left->evaluate();
        double rightVal = right->evaluate();
        return (leftVal > rightVal) ? leftVal : rightVal;
    }
};

#endif