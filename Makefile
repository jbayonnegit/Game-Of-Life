NAME = gameoflife
CC = cc
CFLAGS = -Wall -Wextra -Werror -Iinclude
SRC_DIR = src
OBJ_DIR = obj
FILES = free.c \
		init.c \
		main.c \
		play.c \
		window.c \

OBJS = $(addprefix $(OBJ_DIR)/,$(FILES:%.c=%.o))
SRCS = $(addprefix $(SRC_DIR)/, $(FILES))

$(OBJ_DIR)/%.o : $(SRC_DIR)/%.c
		@mkdir -p $(OBJ_DIR)
		$(CC) $(CFLAGS) -I. -c $< -o $@

all : $(NAME)

$(NAME) : $(OBJS)
	 $(CC) $(OBJS) -o $(NAME) $(CFLAGS) -lSDL2

clean :
	rm -f -r $(OBJ_DIR)
	
fclean : clean 
	rm -f $(NAME)

re : clean fclean all
 	
.PHONY : fclean clean re all bonus
 
