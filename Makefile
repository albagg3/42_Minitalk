CLIENT = client
SERVER = server
CC = gcc
LIBFT_DIR = lib/libft_src_printf
CFLAGS = -Wall -Wextra -Werror -g 
INC_DIR = inc
OBJ_DIR = obj/
SRC_DIR = src/

#FSANITIZE	:= -fsanitize=address -g3

SRC_FILES = client server


SRC 		= 	$(addprefix $(SRC_DIR), $(addsuffix .c, $(SRC_FILES)))
OBJ 		= 	$(addprefix $(OBJ_DIR), $(addsuffix .o, $(SRC_FILES)))
DEPS 		= 	$(addprefix $(OBJ_DIR), $(addsuffix .d, $(SRC_FILES)))

RM = rm -f



$(OBJ_DIR)%.o: $(SRC_DIR)%.c
		mkdir -p $(OBJ_DIR)
		$(CC) -c $(CFLAGS) -MMD $< -o $@

all: makelib
	@$(MAKE) $(CLIENT)
	@$(MAKE) $(SERVER)

makelib:
		@$(MAKE) -C $(LIBFT_DIR)

bonus:
		@$(MAKE) all

-include $(DEPS)
$(CLIENT) :	$(LIBFT_DIR)/libft.a $(OBJ) Makefile
		make -sC $(LIBFT_DIR)
		$(CC) $(CFLAGS) $(FSANITIZE) $(OBJ_DIR)client.o $(LIBFT_DIR)/libft.a -o $(CLIENT)

$(SERVER) :	$(LIBFT_DIR)/libft.a $(OBJ) Makefile
		make -sC $(LIBFT_DIR)
		$(CC) $(CFLAGS) $(FSANITIZE) $(OBJ_DIR)server.o $(LIBFT_DIR)/libft.a -o $(SERVER)

clean:
		$(RM) -r $(OBJ_DIR) $(DEPS)
		$(RM) $(LIBFT_DIR)/libft.a
		@make clean -C $(LIBFT_DIR)

fclean: clean
		$(RM) $(CLIENT)
		$(RM) $(SERVER)

re: fclean all

.PHONY : all clean re fclean makelibft
