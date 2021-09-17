NAME	=	push_swap

SRCS	=	srcs/push_swap.c\
			srcs/utils.c\
			srcs/list_utils.c\
			srcs/moves.c\
			srcs/sort_stacks.c\
			srcs/get_index.c\
			srcs/big_sort.c\
			srcs/big_sort_utils.c\
			srcs/libft_utils.c

OBJS	=	$(SRCS:.c=.o)
CC		=	gcc
CFLAGS	=	-Wall -Wextra -Werror
AR		=	ar rc
RM		=	rm -f

%.o: %.c
	$(CC) -I. -o $@ -c $? $(FLAGS)

$(NAME)		:	$(OBJS)
		$(CC) $(OBJS) -o $(NAME)

all		:	$(NAME)

fclean	:	clean
		$(RM) $(NAME)

clean	:
		$(RM) $(OBJS)

re		:	fclean all

.PHONY	:	all re clean fclean