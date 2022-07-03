NAME	= exe
FLAGS	= -Wall -Wextra -Werror -g3
HEADERS := -I.
SRCS	:= main.c getchar.c stack.c


all		:
		@make $(NAME)

$(NAME)	: $(SRCS) $(LIBFT)
		$(CC) $(FLAGS) $^ -o $@ $(HEADERS)
		
clean	:
		$(RM) $(NAME)

re		:
		@make clean
		@make all

.PHONY : all clean re