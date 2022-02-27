NAME = pipex

SRCS = srcs/main.c srcs/pipex_utils.c srcs/error_functions.c srcs/error_functions2.c

BONUS_SRCS = $(addprefix bonus_srcs/, main_bonus.c pipex_utils_bonus1.c pipex_utils_bonus2.c \
			pipex_utils_bonus3.c pipex_utils_bonus4.c)

all : $(NAME)

$(NAME) : $(SRCS)
	@printf "\033[33;3m----->Compiling Pipex<-----\033[0m\n"
	@make -C libft re
	@cc -Wall -Wextra -Werror $(SRCS) libft/libft.a -o $(NAME)
	@printf "\033[35;3mPipex Compiled Succesfully !\033[0m\n"

bonus :
	@printf "\033[33;3m--------->Compiling Bonus<---------\033[0m\n"
	@make -C libft re
	@cc -Wall -Wextra -Werror $(BONUS_SRCS) libft/libft.a -o $(NAME)
	@printf "\033[35;3mPipex Bonus Compiled Succesfully !\033[0m\n"

clean :
	@make -C libft clean	
	@printf "\033[31;3mObject Files Deleted !\033[0m\n"
	
fclean : clean
	@make -C libft fclean
	@rm -f $(NAME)
	@printf "\033[31;3mPipex Program Deleted\033[0m\n"

re : fclean all

.PHONY : all clean fclean re bonus
