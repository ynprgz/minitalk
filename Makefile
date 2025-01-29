# Variables
NAME = minitalk
CC = cc
CFLAGS = -Wall -Wextra -Werror
RM = rm -rf

# Mandatory
SRC_SERVER = src/server.c
SRC_CLIENT = src/client.c
OBJ_SERVER = $(SRC_SERVER:.c=.o)
OBJ_CLIENT = $(SRC_CLIENT:.c=.o)

# Bonus
SRC_CLIENT_BONUS = src_bonus/client_bonus.c
SRC_SERVER_BONUS = src_bonus/server_bonus.c
OBJ_SERVER_BONUS = $(SRC_SERVER_BONUS:.c=.o)
OBJ_CLIENT_BONUS = $(SRC_CLIENT_BONUS:.c=.o)

# Rules

all: $(NAME)

$(NAME): server client

server:
	@echo "\n Server executable created \n"

client:
	@echo "\n Client executable created \n"

bonus: server_bonus client_bonus

client_bonus:

server_bonus:

clean:

fclean:

re:

.phony: all bonus clean fclean re
