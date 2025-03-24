// Student Name: Dilen Patel
// Date: March 1, 2025
// Project: CMSC 330 Project 2
// Description: Average operator class

#ifndef AVERAGE_H
#define AVERAGE_H

#include "subexpression.h"
#include "expression.h"

class Average : public SubExpression
{
public:
    Average(Expression *left, Expression *right) : SubExpression(left, right)
    {
    }
    double evaluate()
    {
        return (left->evaluate() + right->evaluate()) / 2.0;
    }
};

#endif