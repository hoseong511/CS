NAME	= exe
FLAGS	= -Wall -Wextra -Werror -g3
HEADERS := -I.
SRCS	:= itob.c atoi.c 


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