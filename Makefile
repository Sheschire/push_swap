NAME	=	push_swap
LIBDIR	=	./libft/
LIBFT	=	libft.a

SRCS	=	push_swap.c\
			utils.c

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