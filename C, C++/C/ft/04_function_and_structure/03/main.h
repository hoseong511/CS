#ifndef MAIN_H
# define MAIN_H
# include <stdio.h>
# include <stdlib.h>
# include <ctype.h>
# include <string.h>

enum
{
	SIN = 128,
	COS = 129,
	TAN = 130,
	EXP = 131,
	POW = 132,
};

void	push(double f);
double	pop(void);
double	top_show(void);
int		getch(void);
void	ungetch(int c);
void	clear(void);

#endif