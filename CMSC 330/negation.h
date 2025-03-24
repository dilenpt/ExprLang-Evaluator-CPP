// Student Name: Dilen Patel
// Date: March 1, 2025
// Project: CMSC 330 Project 2
// Description: Negation unary operator class

#ifndef NEGATION_H
#define NEGATION_H

#include "expression.h" // Include the header file for the Expression class

class Negation : public Expression
{
public:
    Negation(Expression *operand)
    {
        this->operand = operand;
    }
    double evaluate()
    {
        return -operand->evaluate();
    }

private:
    Expression *operand;
};

#endif