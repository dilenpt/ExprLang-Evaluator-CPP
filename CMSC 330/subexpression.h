// Student Name: Dilen Patel
// Date: March 1, 2025
// Project: CMSC 330 Project 2
// Description: Modified to support complex expressions

#ifndef SUBEXPRESSION_H
#define SUBEXPRESSION_H

class SubExpression : public Expression
{
public:
    SubExpression(Expression *left, Expression *right);
    static Expression *parse(stringstream &in);

protected:
    Expression *left;
    Expression *right;
};

#endif