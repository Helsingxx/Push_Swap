NAME := push_swap
LIB := ../ft_printf/ft_printf.h push_swap.h
CFILES := main.c init_checks.c  instructions3.c instructions2.c instructions.c \
			ft_atoi.c ft_lstnew.c lib2.c lib3.c manual.c so9sebt.c prev.c
OFILES := $(CFILES:%.c=%.o)
CC := cc
PRINTF := ../ft_printf/libftprintf.a
all: $(NAME)

$(NAME): $(OFILES)
	$(MAKE) -C ../ft_printf
	$(CC) -Wall -Wextra -Werror  $(OFILES) $(PRINTF) -o $(NAME) $(CFLAGS)
	mv $(NAME) ../

%.o: %.c $(LIB)
	$(CC) -Wall -Wextra -Werror $< -c

clean:
	rm -rf $(OFILES)

fclean: clean
	rm -rf ../$(NAME)

re: fclean all

.PHONY:	clean fclean re all bonus