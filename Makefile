CLIENT = client
SERVER = server
CLIENT_BONUS = client_bonus
SERVER_BONUS = server_bonus
CC = gcc
LIBFT_DIR = lib/libft_src_printf
CFLAGS = -Wall -Wextra -Werror -g 
INC_DIR = inc
OBJ_DIR = obj/
SRC_DIR = src/
SRC_BONUS_DIR = src_bonus/
OBJ_BONUS_DIR = obj_bonus/
#FSANITIZE	:= -fsanitize=address -g3

SRC_FILES = client server errors
SRC_BONUS_FILES = client_bonus server_bonus errors_bonus

SRC 		= 	$(addprefix $(SRC_DIR), $(addsuffix .c, $(SRC_FILES)))
OBJ 		= 	$(addprefix $(OBJ_DIR), $(addsuffix .o, $(SRC_FILES)))
DEPS 		= 	$(addprefix $(OBJ_DIR), $(addsuffix .d, $(SRC_FILES)))

SRC_BONUS 		= 	$(addprefix $(SRC_BONUS_DIR), $(addsuffix .c, $(SRC_BONUS_FILES)))
OBJ_BONUS 		= 	$(addprefix $(OBJ_BONUS_DIR), $(addsuffix .o, $(SRC_BONUS_FILES)))
DEPS_BONUS 		= 	$(addprefix $(OBJ_BONUS_DIR), $(addsuffix .d, $(SRC_BONUS_FILES)))

RM = rm -f



$(OBJ_DIR)%.o: $(SRC_DIR)%.c
		mkdir -p $(OBJ_DIR)
		$(CC) -c $(CFLAGS) -MMD $< -o $@

$(OBJ_BONUS_DIR)%.o: $(SRC_BONUS_DIR)%.c
		mkdir -p $(OBJ_BONUS_DIR)
		$(CC) -c $(CFLAGS) -MMD $< -o $@

all: makelib
	@$(MAKE) $(CLIENT)
	@$(MAKE) $(SERVER)

makelib:
		@$(MAKE) -C $(LIBFT_DIR)

bonus:
		@$(MAKE) all
		@$(MAKE) $(CLIENT_BONUS)
		@$(MAKE) $(SERVER_BONUS)
		

-include $(DEPS) $(DEPS_BONUS)
$(CLIENT) :	$(LIBFT_DIR)/libft.a $(OBJ) Makefile
		make -sC $(LIBFT_DIR)
		$(CC) $(CFLAGS) $(FSANITIZE) $(OBJ_DIR)client.o $(OBJ_DIR)errors.o $(LIBFT_DIR)/libft.a -o $(CLIENT)

$(SERVER) :	$(LIBFT_DIR)/libft.a $(OBJ) Makefile
		make -sC $(LIBFT_DIR)
		$(CC) $(CFLAGS) $(FSANITIZE) $(OBJ_DIR)server.o $(OBJ_DIR)errors.o $(LIBFT_DIR)/libft.a -o $(SERVER)

$(CLIENT_BONUS) :	$(LIBFT_DIR)/libft.a $(OBJ) $(OBJ_BONUS) Makefile
		make -sC $(LIBFT_DIR)
		$(CC) $(CFLAGS) $(FSANITIZE) $(OBJ_BONUS_DIR)client_bonus.o $(OBJ_BONUS_DIR)errors_bonus.o $(LIBFT_DIR)/libft.a -o $(CLIENT_BONUS)

$(SERVER_BONUS) :	$(LIBFT_DIR)/libft.a $(OBJ) $(OBJ_BONUS) Makefile
		make -sC $(LIBFT_DIR)
		$(CC) $(CFLAGS) $(FSANITIZE) $(OBJ_BONUS_DIR)server_bonus.o $(OBJ_BONUS_DIR)errors_bonus.o $(LIBFT_DIR)/libft.a -o $(SERVER_BONUS)


clean:
		$(RM) -r $(OBJ_DIR) $(DEPS)
		$(RM) -r $(OBJ_BONUS_DIR) $(DEPS_BONUS)
		$(RM) $(LIBFT_DIR)/libft.a
		@make clean -C $(LIBFT_DIR)

fclean: clean
		$(RM) $(CLIENT)
		$(RM) $(SERVER)
		$(RM) $(CLIENT_BONUS)
		$(RM) $(SERVER_BONUS)

re: fclean all

.PHONY : all clean re fclean makelibft
