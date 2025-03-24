// Student Name: Dilen Patel
// Date: March 1, 2025
// Project: CMSC 330 Project 2
// Description: Exponentiation operator class

#ifndef EXPONENT_H
#define EXPONENT_H

#include <cmath>
#include "subexpression.h"
#include "expression.h"

class Exponent : public SubExpression
{
public:
    Exponent(Expression *left, Expression *right) : SubExpression(left, right)
    {
    }
    double evaluate()
    {
        return pow(left->evaluate(), right->evaluate());
    }
};

#endif