// expression.h
#ifndef EXPRESSION_H // Use a unique name, usually based on the filename in ALL CAPS
#define EXPRESSION_H

// CMSC 330 Advanced Programming Languages
// Project 2 Skeleton
// UMGC CITE
// Spring 2023

// This file contains the definition of the Expression class...
class Expression
{
public:
    virtual double evaluate() = 0;
};

#endif // EXPRESSION_H