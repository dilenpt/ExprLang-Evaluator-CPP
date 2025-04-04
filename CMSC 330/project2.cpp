// Student Name: Dilen Patel
// Date: March 1, 2025
// Project: CMSC 330 Project 2
// Description: Modified main file with error handling and symbol table reset

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

#include "expression.h"
#include "subexpression.h"
#include "symboltable.h"
#include "parse.h"
#include "exception.h"

SymbolTable symbolTable;

void parseAssignments(stringstream &in);

int main()
{
	const int SIZE = 256;
	Expression *expression;
	char paren, comma, line[SIZE];

	ifstream fin;
	fin = ifstream("input.txt");
	if (!(fin.is_open()))
	{
		cout << "File did not open" << endl;
		system("pause");
		return 1;
	}

	while (true)
	{
		fin.getline(line, SIZE);
		if (!fin)
			break;

		// Reset symbol table for each new statement
		symbolTable.clear();

		stringstream in(line, ios_base::in);
		in >> paren;
		cout << line << " ";

		try
		{
			expression = SubExpression::parse(in);
			in >> comma;
			parseAssignments(in);
			double result = expression->evaluate();
			cout << "Value = " << result << endl;
		}
		catch (VariableException &e)
		{
			cout << "Error: " << e.getMessage() << endl;
		}
		catch (string message)
		{
			cout << message << endl;
		}
	}

	system("pause");
	return 0;
}

void parseAssignments(stringstream &in)
{
	char assignop, delimiter;
	string variable;
	double value;

	do
	{
		variable = parseName(in);
		in >> ws >> assignop >> value >> delimiter;
		symbolTable.insert(variable, value);
	} while (delimiter == ',');
}