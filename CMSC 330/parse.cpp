// Student Name: Dilen Patel
// Date: March 1, 2025
// Project: CMSC 330 Project 2
// Description: Modified to support underscores in variable names

#include <cctype>
#include <sstream>
#include <string>
using namespace std;

#include "parse.h"

string parseName(stringstream &in)
{
    char c;
    string name = "";

    in >> ws;
    if (isalpha(in.peek()))
    {
        in >> c;
        name += c;

        // Allow alphanumeric and underscore after first character
        while (isalnum(in.peek()) || in.peek() == '_')
        {
            in >> c;
            name += c;
        }
    }
    return name;
}