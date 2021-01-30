NAME=list
FLAGS=-Wall -Wextra -g -o

$(NAME): 
	@gcc $(FLAGS) $@ $@.c

clean: 
	@rm -rf *.o 
	@rm -rf $(NAME).dSYM
	@rm -rf $(NAME)
