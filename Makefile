NAME = pipex

LIB_NAME = pipex_b.a

OBJECT_FILES = $(addsuffix .o, main pipex_utils error_functions error_functions2)

BONUS_OBJ = $(addsuffix .o, main_bonus pipex_utils_bonus1 pipex_utils_bonus2 \
			pipex_utils_bonus3 pipex_utils_bonus4)

all : $(NAME)

$(NAME) : $(OBJECT_FILES)
	@printf "\033[33;3m----->Compiling Pipex<-----\033[0m\n"
	@make -C libft re
	@cc -Wall -Wextra -Werror $(OBJECT_FILES) libft/libft.a -o $(NAME)
	@printf "\033[35;3mPipex Compiled Succesfully !\033[0m\n"

bonus : $(LIB_NAME)

$(LIB_NAME) : $(BONUS_OBJ)
	@printf "\033[33;3m--------->Compiling Bonus<---------\033[0m\n"
	@make -C libft re
	@ar -rc $(LIB_NAME) $(BONUS_OBJ)
	@cc -Wall -Wextra -Werror $(LIB_NAME) libft/libft.a -o $(NAME)
	@printf "\033[35;3mPipex Bonus Compiled Succesfully !\033[0m\n"

%.o : %.c
	@cc -Wall -Wextra -Werror -c $< -o $@

clean :
	@make -C libft clean	
	@rm -f $(OBJECT_FILES) $(BONUS_OBJ)
	@printf "\033[31;3mObject Files Deleted !\033[0m\n"
	
fclean : clean
	@make -C libft fclean
	@rm -f $(NAME) $(LIB_NAME)
	@printf "\033[31;3mPipex Program Deleted\033[0m\n"

re : fclean all

.PHONY : all clean fclean re bonus
