
/*
In C++, when you have an expression with operands of different types, the compiler follows a set of rules to determine the resulting type of the expression. 
This process is known as "type promotion" or "type conversion." The rules are designed to ensure that the operands are compatible and that the result has a meaningful type.

Here are the general rules for arithmetic operations in C++:

Integral Promotion: If an operand is smaller than an int, it is promoted to int before the operation. This applies to types like char and short.


Usual Arithmetic Conversions: 
The usual arithmetic conversions involve a set of rules to determine the resulting type based on the types of the operands.

    If one operand is long int and the other is int, the int is promoted to long int before the operation.

    If one operand is unsigned long int and the other is long int, the long int is converted to unsigned long int.

    If one operand is float and the other is an integral type, the integral type is converted to float.

    If one operand is double and the other is an integral type or float, the integral type or float is converted to double.

Result Type: The result of the operation has the type determined by the usual arithmetic conversions.

Here's a simple example to illustrate:
*/
#include <iostream>
using namespace std;

int main() {
    long int a = 10;
    int b = 5;

    // Usual arithmetic conversion: int is promoted to long int
    long int result = a + b;

    std::cout << "Result: " << result << std::endl;

    return 0;
}

// In this example, b is an int, but it gets promoted to long int before the addition operation with a. The result of the addition is also of type long int

