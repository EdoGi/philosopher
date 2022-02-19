# *--------- SOURCES ---------* 

SRCS_DIR	= ./srcs/
SRCS_B_DIR	= ./srcs_bonus/

SRCS		=	\
				philosopher.c \
				\

SRCS_B	=		\

# *-------- GENERALS --------* 

CC		=	clang
CFLAGS	=	-Wall -Werror -Wextra -g -pthread -Iinclude
# CFLAGS = -Wall -Wextra -Werror -pthread -g3 -fsanitize=thread -Iinclude

RM		=	rm -rf

NAME	= 	Philo

# *-------- COMPILE --------* 

%.o : %.c
			@$(CC) $(CFLAGS) -pthreads -o $@ -c $< -Iinclude

$(NAME):	$(OBJS)
			@$(CC) $(CFLAGS) $(OBJS) -o $(NAME)
			@echo "$(NAME) created"

$(NAME)_bonus :	$(OBJS_B)
			@$(CC) $(CFLAGS) $(OBJS_B) -o $(NAME)_bonus
			@echo "$(NAME)_bonus created"

# *======== RULES ========* 

all	:		${NAME}

bonus:		${NAME}_bonus

clean:
			@$(RM) $(OBJS) $(OBJS_B)
			@echo ".o deleted"

fclean:		clean
			@$(RM) $(NAME) $(NAME)_bonus
			@echo "$(NAME) and $(NAME)_bonus deleted"

re:			fclean all

.PHONY:		all clean flcean re bonus%                                                            