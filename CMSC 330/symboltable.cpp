// Student Name: Dilen Patel
// Date: March 1, 2025
// Project: CMSC 330 Project 2
// Description: Modified to include error handling and table clearing

#include <string>
#include <vector>
using namespace std;

#include "symboltable.h"
#include "exception.h"

void SymbolTable::insert(string variable, double value)
{
    if (exists(variable))
        throw VariableException("Variable " + variable + " is already defined");

    const Symbol &symbol = Symbol(variable, value);
    elements.push_back(symbol);
}

double SymbolTable::lookUp(string variable) const
{
    for (int i = 0; i < elements.size(); i++)
        if (elements[i].variable == variable)
            return elements[i].value;

    throw VariableException("Variable " + variable + " is not defined");
}

void SymbolTable::clear()
{
    elements.clear();
}

bool SymbolTable::exists(string variable) const
{
    for (int i = 0; i < elements.size(); i++)
        if (elements[i].variable == variable)
            return true;
    return false;
}