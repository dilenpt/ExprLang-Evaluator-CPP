// Student Name: Dilen Patel
// Date: March 1, 2025
// Project: CMSC 330 Project 2
// Description: Extended conditional quaternary operator class

#ifndef EXTENDEDCONDITIONAL_H
#define EXTENDEDCONDITIONAL_H

#include "expression.h"

class ExtendedConditional : public Expression
{
public:
    ExtendedConditional(Expression *condition, Expression *negExpression,
                        Expression *zeroExpression, Expression *posExpression)
    {
        this->condition = condition;
        this->negExpression = negExpression;
        this->zeroExpression = zeroExpression;
        this->posExpression = posExpression;
    }
    double evaluate()
    {
        double condVal = condition->evaluate();
        if (condVal < 0)
            return negExpression->evaluate();
        else if (condVal == 0)
            return zeroExpression->evaluate();
        else
            return posExpression->evaluate();
    }

private:
    Expression *condition;
    Expression *negExpression;
    Expression *zeroExpression;
    Expression *posExpression;
};

#endif