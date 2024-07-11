#include <iostream>
#include "libExceptions.h"
#include "libGeneralBackpackProblem.h"
#include"libRecursionBackpackProblem.h"

using namespace std;

int main()
{
	cout << "Program 01:\n";
	f_generalBackpackProblem();
	cout << "\nProgram 02:\n";
	f_recursionBackpackProblem();
	return 0;
}
