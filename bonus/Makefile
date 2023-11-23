NAME := checker
LIB := ../ft_printf/ft_printf.h push_swap_bonus.h
GNL := get_next_line.c get_next_line_utils.c
BCFILES := bonus.c instructions3_bonus.c instructions2_bonus.c instructions_bonus.c ft_atoi_bonus.c lib3_bonus.c lib2_bonus.c lib_bonus.c ft_lstnew_bonus.c exit.c init_checks.c
BOFILES := $(BCFILES:%.c=%.o) $(GNL:%.c=%.o)
CC := cc
PRINTF := ../ft_printf/libftprintf.a
all: $(NAME)

$(NAME): $(BOFILES)
	$(MAKE) -C ../ft_printf
	$(CC) -Wall -Wextra -Werror $(BOFILES) $(PRINTF) -o $(NAME)
	mv $(NAME) ../

%.o: %.c $(LIB)
	$(CC) -Wall -Wextra -Werror $< -c

clean:
	rm -rf $(BOFILES)

fclean: clean
	rm -rf ../$(NAME)

re: fclean all

.PHONY:	clean fclean re all bonus