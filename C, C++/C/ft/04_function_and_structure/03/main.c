#include "main.h"

#define MAXOP 100
#define NUMBER '0'

/*getop: get next character or numeric operand */
int	getop(char s[])
{
	int i, c;
	while ((s[0] = c = getch()) == ' ' || c == '\t')
		;
	s[1] = '\0';
	i = 0;
	if (!isdigit(c) && c != '.')
	{
		if ((s[0] = c) == '-' && isdigit(s[1] = c = getch()))
			i++;
		else
			return c;
	}
	if (isdigit(c))
		while (isdigit(s[++i] = c = getch()))
			;
	if (c == '.')
		while (isdigit(s[++i] = c = getch()))
			;
	s[i] = '\0';
	if (c != EOF)
		ungetch(c);
	return NUMBER;
}

int main(void)
{
	int type;
	double op2;
	char s[MAXOP];

	while (( type = getop(s) ) != EOF)
	{
		switch (type)
		{
			case NUMBER:
				push(atof(s));
				break;
			case '+':
				push(pop() + pop());
				break;
			case '-':
				op2 = pop();
				push(pop() - op2);
				break;
			case '*':
				push(pop() * pop());
				break;
			case '/':
				op2 = pop();
				if (op2 != 0.0)
					push(pop() / op2);
				else
					printf("error: zero divisor\n");
				break;
			case '%':
				op2 = pop();
				if (op2 != 0.0)
					push((int)pop() % (int)op2);
				else
					printf("error: zero modulus\n");
				break;
			case 'c':
				clear();
				printf("clear\n");
				break;
			case '\n':
				printf("\t%.8g\n", top_show());
				break;
			default:
				printf("erorr: unknown command %s\n", s);
				break;
		}
	}
	return 0;
}
