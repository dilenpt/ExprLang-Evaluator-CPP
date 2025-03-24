Expression Language Evaluator (CMSC 330 Project 2)

This C++ project is an expression evaluator that parses and evaluates expressions written in a custom, fully parenthesized expression language. It supports arithmetic, logical, and conditional operations, including custom ternary and quaternary operators. 

 📚 Project Overview

This project was completed for CMSC 330 . It extends a provided skeleton to support a more complex expression language and to evaluate expressions from an input file.

Each line in the input represents a statement composed of an expression followed by variable assignments. Expressions are stored in a binary tree and evaluated recursively using a symbol table for variable lookups.



 🧾 Grammar


statement → expression ',' assignments ';'
expression → '(' expressions ')'
expressions →
    unary_expression |
    binary_expression |
    ternary_expression |
    quaternary_expression |
    operand

unary_expression → expression '~'
binary_expression → expression binary_operator expression
binary_operator → '+' | '-' | '*' | '/' | '%' | '^' | '<' | '>' | '&'
ternary_expression → expression '?' expression expression
quaternary_expression → expression '#' expression expression expression

operand → literal | variable | expression

assignments → assignments ',' assignment | assignment
assignment → variable '=' literal


- `variable`: `[a-zA-Z][a-zA-Z0-9_]*` (underscores allowed after the first character)
- `literal`: Unsigned **floating-point** values supported

---

 🔧 Features Implemented

- Fully parenthesized expression parsing
- Custom binary operators:
  - `^`: Exponentiation  
  - `<`: Minimum  
  - `>`: Maximum  
  - `&`: Average
- Postfix unary operator `~` (negation)
- Custom ternary operator `?`
- Custom quaternary operator `#`
- Floating-point literal support
- Error handling for:
  - Uninitialized variable usage
  - Multiple assignments to the same variable in one statement
- Fresh symbol table for each statement (no carryover between statements)

---

 📂 Project Structure


/src
  ├── main.cpp                   # Entry point
  ├── ExpressionEvaluator.h/.cpp # Core expression evaluation logic
  ├── Parser.h/.cpp              # Grammar parser
  ├── Tokenizer.h/.cpp           # Token handling and validation
  ├── SymbolTable.h/.cpp         # Variable storage and lookup
  ├── ExpressionTree.h/.cpp      # Expression tree representation
  ├── Exceptions.h/.cpp          # Custom exception classes
  ├── input.txt                  # Sample input file with statements
  └── ...                        # Other class files as needed


> Note: One-liner classes/functions are implemented inline in `.h` files as permitted.


 🚀 How to Run

1. Compile the program:
  
   g++ -std=c++17 *.cpp -o evaluator
   

2. Ensure `input.txt` is in the same directory, then run:
  
   ./evaluator
   

3. Output will be displayed for each expression in the input file.

---

 📑 Sample Input

((3 + x) * (y ^ 2)), x = 4, y = 5;
((x < y) ? (x + 1) (y + 1)), x = 3, y = 7;
((x # y z w)), x = -1, y = 10, z = 20, w = 30;




 ✅ Test Plan

Test cases cover:

- Basic arithmetic and precedence
- All new operators (`^`, `<`, `>`, `&`, `~`, `?`, `#`)
- Floating-point literals
- Underscore in variable names
- Error cases:
  - Re-declared variables
  - Uninitialized variable use

Example Output:


Result: 175.0
Result: 4.0
Result: 10.0




 🧠 Lessons Learned

- Recursive descent parsing for complex grammars
- Expression trees and post-order evaluation
- Custom operator semantics and postfix handling
- Error detection and reporting in a controlled environment
- C++ memory and class organization best practices



 ✍️ Author

Dilen Patel  
 Spring 2025  
Project 2: Expression Language Evaluator


Let me know if you'd like me to generate a `.gitignore` or a sample `input.txt` as well!
