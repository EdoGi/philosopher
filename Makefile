# *--------- SOURCES ---------* 

SRCS_DIR	= ./srcs/
SRCS_B_DIR	= ./srcs_bonus/

SRCS		=	\
				main.c	\
				starter_closer/initializer.c	\
				starter_closer/finisher.c		\
				starter_closer/parser.c			\
				user/routiniser.c				\
				user/checker.c					\
				user/eater.c					\
				manager/utiliser.c				\
				manager/writer.c				\
				manager/timer.c					\
				\

SRCS_B	=		\

# *--------- OBJECTS ---------* 

OBJS		=	$(addprefix $(SRCS_DIR), $(SRCS:.c=.o))
OBJS_B		=	$(addprefix $(SRCS_B_DIR), $(SRCS_B:.c=.o))

# *-------- INCLUDE --------* 

INCLUDE_DIR = -I ./include
INC = ./include/philosopher.h

# *-------- GENERALS --------* 

NAME	= 	Philo

CC		=	clang
CFLAGS	=	-Wall -Werror -Wextra -g -pthread
# CFLAGS = -Wall -Wextra -Werror -pthread -g3 -fsanitize=thread
# CFLAGS = -Wall -Wextra -Werror -pthread -g3 -fsanitize=address

RM		=	rm -rf

# *-------- COMPILE --------* 

all	:		$(NAME)

%.o : %.c
			@$(CC) $(CFLAGS) -o $@ -c $< $(INCLUDE_DIR)

$(NAME):	$(OBJS) $(INC)
			@$(CC) $(CFLAGS) $(OBJS) $(INCLUDE_DIR) -o $(NAME)
			@echo "$(NAME) created"
 
$(NAME)_bonus :	$(OBJS_B) $(INC)
			@$(CC) $(CFLAGS) $(OBJS_B) $(INCLUDE_DIR) -o $(NAME)_bonus
			@echo "$(NAME)_bonus created"

# *======== RULES ========* 

bonus:		${NAME}_bonus

clean:
			@$(RM) $(OBJS) $(OBJS_B)
			@echo ".o deleted"

fclean:		clean
			@$(RM) $(NAME) $(NAME)_bonus
			@echo "$(NAME) and $(NAME)_bonus deleted"

re:			fclean all

.PHONY:		all clean flcean re bonus%                                                            