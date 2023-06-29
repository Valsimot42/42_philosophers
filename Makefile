# Program
NAME	= philo

# Compilation
CC		= gcc
CFLAGS	= -Wall -Werror -Wextra -g
# FSANITIZE = -fsanitize=address
# add $(FSANITIZE) to flags

HEADER	= ./philo.h	
# Sources 
SRC_PATH = src/

SRC		=	main.c			\
			utils.c			\
			libft_utils.c	\
			mutex.c			\
			threads.c		\
		
SRCS	= $(addprefix $(SRC_PATH), $(SRC))

# Objects
OBJ_PATH	= obj/
OBJ			= $(SRC:.c=.o)
OBJS		= $(addprefix $(OBJ_PATH), $(OBJ))

# Colors
NC			:= \033[0m
RED			:= \033[0;31m
GREEN		:= \033[0;32m
BLUE		:= \033[0;34m

# Rules
all: $(NAME) 

$(OBJ_PATH)%.o : $(SRC_PATH)%.c $(HEADER)
	@echo "$(GREEN)Compiling: $< $(NC)"
	@$(CC) -c $(CFLAGS) -o $@ $<

$(OBJ_PATH):
	@mkdir $(OBJ_PATH)

$(NAME): $(OBJ_PATH) $(OBJS)
	@$(CC) -o $(NAME) $(OBJS) $(CFLAGS)
	@echo "$(BLUE) $(NAME) created $(NC)"

bonus: all

clean:
	@echo "Cleaning: $(RED) $(OBJ_PATH) $(NC)"
	@rm -rf $(OBJ_PATH)

fclean:
	@echo "Cleaning:$(RED) $(NAME) $(NC)"
	@rm -f $(NAME)

re:	clean fclean all

norm:
	cd src && norminette -R CheckForbiddenSourceHeader $(SRC)
	norminette -R CheckForbiddenSourceHeader $(HEADER)

#valgrind options
# --leak-check=full --show-leak-kinds=all --ignore-fn=readline ./minishell
# --leak-check=full --show-leak-kinds=all --trace-children=yes ./minishell
valg:
	valgrind --leak-check=full --trace-children=yes --track-fds=yes -s ./minishell

.PHONY: all, libft, clean, fclean
