// Student Name: Dilen Patel
// Date: March 1, 2025
// Project: CMSC 330 Project 2
// Description: Conditional ternary operator class

#ifndef CONDITIONAL_H
#define CONDITIONAL_H

#include "expression.h"

class Conditional : public Expression
{
public:
    Conditional(Expression *condition, Expression *trueExpression, Expression *falseExpression)
    {
        this->condition = condition;
        this->trueExpression = trueExpression;
        this->falseExpression = falseExpression;
    }
    double evaluate()
    {
        if (condition->evaluate() != 0)
            return trueExpression->evaluate();
        else
            return falseExpression->evaluate();
    }

private:
    Expression *condition;
    Expression *trueExpression;
    Expression *falseExpression;
};

#endif