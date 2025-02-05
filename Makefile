# Variables
NAME = server
NAME_C = client

NAME_BONUS = server_bonus
NAME_C_BONUS = client_bonus
CFLAGS = -Wall -Wextra -Werror
RM = rm -rf
LIBFT_PATH = libft
LIBFT_A = $(LIBFT_PATH)/libft.a

# Mandatory
SRC_SERVER = src/server.c
SRC_CLIENT = src/client.c
# Bonus
SRC_CLIENT_BONUS = src_bonus/client_bonus.c
SRC_SERVER_BONUS = src_bonus/server_bonus.c

# Rules

all: $(LIBFT_A) server client

$(LIBFT_A):
	@$(MAKE) -C $(LIBFT_PATH)

server: $(LIBFT_A) $(SRC_SERVER)
	@cc $(CFLAGS) -o $(NAME) $(SRC_SERVER) $(LIBFT_A)
	@echo "\n Server executable created \n"

client: $(LIBFT_A) $(SRC_CLIENT)
	@cc $(CFLAGS) -o $(NAME_C) $(SRC_CLIENT) $(LIBFT_A)
	@echo "\n Client executable created \n"

bonus: server_bonus client_bonus

client_bonus: $(LIBFT_A) $(SRC_CLIENT_BONUS)
	@cc $(CFLAGS) -o $(NAME_C_BONUS) $(SRC_CLIENT_BONUS) $(LIBFT_A)
	@echo "\n Client executable created \n"

server_bonus: $(LIBFT_A) $(SRC_SERVER_BONUS)
	@cc $(CFLAGS) -o $(NAME_BONUS) $(SRC_SERVER_BONUS) $(LIBFT_A)
	@echo "\n Server executable created \n"

clean:
	@$(MAKE) -C $(LIBFT_PATH) clean

fclean: clean
	@$(MAKE) -C $(LIBFT_PATH) fclean
	@$(RM) $(NAME) $(NAME_C) $(NAME_BONUS) $(NAME_C_BONUS)

re: fclean all

.phony: all bonus clean fclean re
