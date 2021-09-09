NAME	=	push_swap
LIBDIR	=	./libft/
LIBFT	=	libft.a

SRCS	=	srcs/push_swap.c\
			srcs/utils.c\
			srcs/list_utils.c\
			srcs/moves.c\
			srcs/moves_rrr.c\
			srcs/sort_stacks.c\
			srcs/get_index.c\
			srcs/big_sort.c

OBJS	=	$(SRCS:.c=.o)
CC		=	gcc
CFLAGS	=	-Wall -Wextra -Werror
AR		=	ar rc
RM		=	rm -f

%.o: %.c
	$(CC) -I. -o $@ -c $? $(FLAGS)

$(NAME)		:	$(OBJS)
		make all -C $(LIBDIR)
		$(CC) $(OBJS) $(LIBDIR)/$(LIBFT) -o $(NAME)

all		:	$(NAME)

fclean	:	clean
		$(RM) $(NAME)
		make fclean -C $(LIBDIR)

clean	:
		$(RM) $(OBJS)
		make clean -C $(LIBDIR)

re		:	fclean all

.PHONY	:	all re clean fclean