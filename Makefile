NAME := push_swap

all:
	$(MAKE) -C main

clean:
	$(MAKE) -C ft_printf clean
	$(MAKE) -C main clean
	$(MAKE) -C bonus clean

fclean: clean
	$(MAKE) -C ft_printf fclean
	$(MAKE) -C main fclean
	$(MAKE) -C bonus fclean

re: fclean all
	$(MAKE) -C main re

bonus:
	$(MAKE) -C bonus

.PHONY:	clean fclean re all bonus