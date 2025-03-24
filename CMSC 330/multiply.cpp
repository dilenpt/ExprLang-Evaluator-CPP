// multiply.cpp
#include "multiply.h"

Multiply::Multiply(Expression *left, Expression *right) : SubExpression(left, right)
{
}

double Multiply::evaluate()
{
    return left->evaluate() * right->evaluate();
}