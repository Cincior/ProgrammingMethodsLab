#include "libSolutions.h"

string f_cleanExpression(string expression)
{
	string cleanedExpression;

	for (char element : expression) // pozostawienie tylko liter i operatorow znacz¹cych
	{
		if (isalpha(element) || element == '=' || element == '<' || element == '>' || element == '+' || element == '-' || element == '*' || element == '/' || element == '%' || element == '^' || element == '~' || element == '(' || element == ')')
		{
			cleanedExpression += element;
		}
	}
	return cleanedExpression;
}

bool f_containsLetters(string input) 
{
	for (char character : input) 
	{
		if (!isalpha(character)) 
		{
			return false; // Jeœli znaleziono znak, który nie jest liter¹, zwraca false
		}
	}
	return true;
}

string f_cleanExpressionONP(vector<string> expression)
{
	string cleanedExpression;
	for (string element : expression) // pozostawienie tylko liter i operatorow znacz¹cych
	{
		if (f_containsLetters(element) || element == "=" || element == "<" || element == ">" || element == "+" || element == "-" || element == "*" || element == "/" || element == "%" || element == "^" || element == "~")
		{
			cleanedExpression += element;
		}
	}
	for (string element : expression)
	{
		if (element != "(" && element != ")" )
		{
			cleanedExpression += element;
		}
	}
	return cleanedExpression;
}

string f_ONP_To_INF(vector<string> expression)
{
	stack<string> stackElements;
	stack<int> stackPriorities;
	string tmp = "", element;
	int charsCounter = 0, operatorsCounter = 0;
	if (!f_validateONP(expression))
	{
		return "Error";
	}
	for (int i = 0; i < expression.size(); i++) 
	{
		if (isalpha(expression[i][0])) 
		{
			stackElements.push(expression[i]);
			stackPriorities.push(f_checkPriority(expression[i][0]));
			charsCounter++;
		}
		else 
		{
			tmp = "";
			if (expression[i] != "~") 
			{
				operatorsCounter++;
				if (stackPriorities.top() <= f_checkPriority(expression[i][0]))
				{
					element = stackElements.top();
					tmp = "(" + element + ")";
					stackElements.pop();
				}
				else
				{
					element = stackElements.top();
					tmp = element;
					stackElements.pop();
				}
				stackPriorities.pop();
				if (stackPriorities.top() < f_checkPriority(expression[i][0]))
				{
					element = stackElements.top();
					tmp = "(" + element + ")" + expression[i] + tmp;
					stackElements.pop();
				}
				else
				{
					element = stackElements.top();
					tmp = element + expression[i] + tmp;
					stackElements.pop();
				}
				stackPriorities.pop();
			}
			else 
			{
				if (stackPriorities.top() <= f_checkPriority(expression[i][0]))
				{
					element = stackPriorities.top();
					tmp = expression[i] + "(" + element + ")";
					stackPriorities.pop();
				}
				else
				{
					element = stackElements.top();
					tmp = expression[i] + element;
					stackElements.pop();
				}
				stackPriorities.pop();
			}
			stackElements.push(tmp);
			stackPriorities.push(f_checkPriority(expression[i][0]));
		}
	}
	if (charsCounter - 1 == operatorsCounter)
	{
		return stackElements.top();
	}
	else
	{
		return "error";
	}
}

string f_INF_To_ONP(string expression)
{
	expression = f_cleanExpression(expression);
	if (!f_validateINF(expression))
	{
		return "Error";
	}
	string createdExpression = "";
	stack<char> stack;
	for (char element : expression)
	{
		if (isalpha(element))
		{
			createdExpression += element;
		}
		else if (element == '(')
		{
			stack.push(element);
		}
		else if (element == ')')
		{
			while (!stack.empty() && stack.top() != '(') 
			{
				createdExpression += stack.top();
				stack.pop();
			}

			if (!stack.empty() && stack.top() == '(') 
			{
				stack.pop(); // Usuniêcie '('
			}
			else 
			{
				return "Error"; // brak zamkniêcia nawiasu
			}
		}
		else
		{
			int priority = f_checkPriority(element);
			while (!stack.empty() && ( (priority <= f_checkPriority(stack.top()) && f_checkConnection(element) == 2) || (priority < f_checkPriority(stack.top()) && f_checkConnection(element) == 1)) )
			{
				createdExpression += stack.top();
				stack.pop();
			}
			stack.push(element);
			
		}
		
	}

	while (!stack.empty())
	{
		createdExpression += stack.top();
		stack.pop();
	}
	return createdExpression;
}

int f_checkPriority(char sign)
{
	if (sign == '=')
	{
		return 0;
	}
	else if (sign == '<' || sign == '>')
	{
		return 1;
	}
	else if (sign == '+' || sign == '-')
	{
		return 2;
	}
	else if (sign == '*' || sign == '/' || sign == '%')
	{
		return 3;
	}
	else if (sign == '^')
	{
		return 4;
	}
	else if (sign == '~')
	{
		return 5;
	}
	else if (isalpha(sign))
	{
		return 6;
	}
	else
	{
		return -1; 
	}
}

int f_checkConnection(char sign)
{
	if (sign == '<' || sign == '>' || sign == '+' || sign == '-' || sign == '*' || sign == '/' || sign == '%')
	{
		return 2; //lewostronna ³¹cznoœæ
	}
	else
	{
		return 1;
	}
}

bool f_validateINF(string expression)
{
	int letterStreak = 0, operatorStreak = 0;

	for (char element : expression)
	{
		if (isalpha(element))
		{
			letterStreak++;
			operatorStreak = 0;
		}
		else if (element == '(')
		{
			letterStreak = 0;
			operatorStreak = 0;
		}
		else if (element == ')')
		{
			letterStreak = 0;
			operatorStreak = 0;
		}
		else
		{
			letterStreak = 0;
			if (element != '~')
			{
				operatorStreak++;
			}
		}
		if (letterStreak > 1 || operatorStreak > 1)
		{
			return false;
		}
	}
	return true;
}

bool f_validateONP(vector<string> expression)
{
	int lettersCounter = 0, operatorCounter = 0;
	for (string element : expression)
	{
		if (f_containsLetters(element))
		{
			lettersCounter++;
		}
		else if(element != "~")
		{
			operatorCounter++;
		}
		else
		{
			continue;
		}
	}

	if (lettersCounter - 1 != operatorCounter)
	{
		return false;
	}
	return true;
}
