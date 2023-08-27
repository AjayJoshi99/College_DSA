#include <stdio.h>
#include <math.h>
char expr[100];
char op[100];
int top = -1;

int pop()
{
	if (top == -1)
		return 0;
	top -= 1;
	return op[top + 1];
}
void push(char x)
{
	top += 1;
	op[top] = x;
}
int pre(char a)
{
	switch (a)
	{
	case '+':
	case '-':
		return 1;
	case '*':
	case '/':
	case '%':
		return 2;
	case '^':
		return 3;
	default:
		return 0;
	}
}
int main()
{
	printf("\nName  : Ajay Joshi\nEnrollment No. : 92201703192\n\n");
	printf("Enter Expression  : ");
	gets(expr);
	printf("Postfix of given expression is :  ");
	for (int i = 0; i <= 100; i++)
	{
		if (expr[i] == '\0')
			break;
		if ((expr[i] >= 'a' && expr[i] <= 'z') || (expr[i] >= 'A' && expr[i] <= 'Z') || (expr[i] <= '9' && expr[i] >= '0'))
		{
			printf("%c", expr[i]);
		}
		else if (expr[i] == '+' || expr[i] == '-' || expr[i] == '/' || expr[i] == '*' || expr[i] == '^')
		{
			if (top != -1)
			{
				if (pre(op[top]) < pre(expr[i]))
				{
					push(expr[i]);
				}
				else
				{
					while (pre(expr[i]) <= pre(op[top]))
					{
						if (op[top] != '(' && top != -1)
						{
							printf("%c", pop());
						}
					}
					push(expr[i]);
				}
			}
			else
			{
				push(expr[i]);
			}
		}
		else if (expr[i] == '(')
		{
			push(expr[i]);
		}
		else if (expr[i] == ')')
		{
			char temp = pop();
			while (temp != '(')
			{
				printf("%c", temp);
				temp = pop();
			}
		}
		else
		{
			printf("\n\n\nInvalid Operand!!!  : %c ", expr[i]);
			return 0;
		}
	}

	for (int i = top; i > -1; i--)
	{
		printf("%c", op[i]);
	}
	printf("\n\n");
	return 0;
}