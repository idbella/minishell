NAME=minishell
all:$(NAME)
$(NAME):
	#make -C libft
	gcc -c -Wall -Wextra -Werror *.c
	gcc -Wall -Wextra -Werror *.o libft/libft.a -o $(NAME)
clean:
	#make -C libft/ clean
	rm -rf *.o
fclean: clean
	#make -C libft/ fclean
	rm -rf $(NAME)
re:fclean 
	make all