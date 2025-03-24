// Student Name: Dilen Patel
// Date: March 1, 2025
// Project: CMSC 330 Project 2
// Description: Remainder operator class

#ifndef REMAINDER_H
#define REMAINDER_H

#include "subexpression.h"
#include "expression.h"

class Remainder : public SubExpression
{
public:
    Remainder(Expression *left, Expression *right) : SubExpression(left, right)
    {
    }
    double evaluate()
    {
        return (int)left->evaluate() % (int)right->evaluate();
    }
};

#endif