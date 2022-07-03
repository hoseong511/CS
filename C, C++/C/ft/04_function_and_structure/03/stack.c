#include "main.h"
#define MAXVAL 100

int sp = 0;
double val[MAXVAL];

/* push: push f onto value stack */
void	push(double f)
{
	if (sp < MAXVAL)
		val[sp++] = f;
	else
		printf("error: stack full, catn't push %g\n", f);
}

/*pop: pop and return top value from stack */
double	pop(void)
{
	if (sp > 0)
		return val[--sp];
	else
	{
		printf("error: stack empty\n");
		return 0.0;
	}
}

double top_show(void)
{
	if (sp > 0)
		return val[sp - 1];
	else
	{
		printf("stack empty\n");
		return 0.0;
	}
}

void	clear(void)
{
	if (sp > 0)
		sp = 0;
	else
		printf("error: stack empty\n");
}