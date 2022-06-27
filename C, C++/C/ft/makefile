NAME	= exe
FLAGS	= -Wall -Wextra -Werror -g3
LIBFT	= libft/libft.a
SRCS	:= expand.c


all		:
		@make -C $(dir $(LIBFT))
		@make $(NAME)

$(NAME)	: $(SRCS) $(LIBFT)
		$(CC) $(FLAGS) $^ -o $@
clean	:
		$(RM) $(NAME)
