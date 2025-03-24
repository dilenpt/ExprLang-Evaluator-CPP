// Student Name: Dilen Patel
// Date: March 1, 2025
// Project: CMSC 330 Project 2
// Description: Exception class for variable-related errors

#ifndef EXCEPTION_H
#define EXCEPTION_H

#include <string>
using namespace std;

class VariableException
{
public:
    VariableException(string message)
    {
        this->message = message;
    }
    string getMessage() const
    {
        return message;
    }

private:
    string message;
};

#endif