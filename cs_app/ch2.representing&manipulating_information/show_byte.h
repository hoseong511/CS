#ifndef SHOW_BYTE_H
# define SHOW_BYTE_H

# include <stdio.h>
# include <string.h>

typedef unsigned char *byte_pointer;

void	show_bytes(byte_pointer start, size_t len);
void	show_int(int x);
void	show_float(float x);
void	show_pointer(void *x);
void	test_show_bytes(int val);

#endif