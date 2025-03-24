// Student Name: Dilen Patel
// Date: March 1, 2025
// Project: CMSC 330 Project 2
// Description: Division operator class

#ifndef DIVIDE_H
#define DIVIDE_H

#include "subexpression.h"
#include "expression.h"

class Divide : public SubExpression
{
public:
    Divide(Expression *left, Expression *right) : SubExpression(left, right)
    {
    }
    double evaluate()
    {
        return left->evaluate() / right->evaluate();
    }
};

#endif