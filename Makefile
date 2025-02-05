# Variables
NAME = server
NAME_C = client

NAME_BONUS = server_bonus
NAME_C_BONUS = client_bonus
CFLAGS = -Wall -Wextra -Werror
RM = rm -rf
LIBFT = libft/libft.a

# Mandatory
SRC_SERVER = src/server.c
SRC_CLIENT = src/client.c
# Bonus
SRC_CLIENT_BONUS = src_bonus/client_bonus.c
SRC_SERVER_BONUS = src_bonus/server_bonus.c

# Rules

all: $(LIBFT) server client

$(LIBFT):
	@$(MAKE) -C libft

server: $(LIBFT) $(SRC_SERVER)
	@cc $(CFLAGS) -o $(NAME) $(SRC_SERVER) $(LIBFT)
	@echo "\n Server executable created \n"

client: $(LIBFT) $(SRC_CLIENT)
	@cc $(CFLAGS) -o $(NAME_C) $(SRC_CLIENT) $(LIBFT)
	@echo "\n Client executable created \n"

bonus: server_bonus client_bonus

client_bonus: $(LIBFT) $(SRC_CLIENT_BONUS)
	@cc $(CFLAGS) -o $(NAME_C_BONUS) $(SRC_CLIENT_BONUS) $(LIBFT)
	@echo "\n Server executable created \n"

server_bonus: $(LIBFT) $(SRC_SERVER_BONUS)
	@cc $(CFLAGS) -o $(NAME_BONUS) $(SRC_SERVER_BONUS) $(LIBFT)
	@echo "\n Server executable created \n"

clean:
	@$(MAKE) -C libft clean

fclean: clean
	@$(MAKE) -C libft fclean
	@rm -rf $(SRC_SERVER) $(SRC_CLIENT) $(SRC_CLIENT_BONUS) $(SRC_SERVER_BONUS)

re: fclean all

.phony: all bonus clean fclean re
