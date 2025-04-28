#-----------------------------------
#          NAMES and PATHS          
#-----------------------------------

# make compile the final executable 'pipex'
# make test compile the final executable 'test'
# make checker compile the final executable 'checker'

# Name of final executable
NAME		=	pipex
TEST		=	test

# Libft - static library
LIBFT_PATH	=	libft/
LIBFT_NAME	=	libft.a
LIBFT		=	$(LIBFT_PATH)$(LIBFT_NAME)

# Includes
INC			=	-I ./include/ \
				-I ./libft/include/

# Source files pipex
SRC_PATH		=	source/
SRC_PIPEX		=	0_pipex_main.c \
					0_pipex_main_utils.c \
					1_error.c \
					1_init_pipex.c
SRCS_PIPEX		=	$(addprefix $(SRC_PATH), $(SRC_PIPEX))

# Source files test
TEST_DIR = tests
SRC_DIR = source
SRCS_TEST		=	$(TEST_DIR)/0_tests.c

# Object files
# List of object files (define the name of .o files from .c files)

OBJ_PATH_PIPEX		= obj/pipex/
OBJ_PATH_TEST		= obj/test/

OBJ_PIPEX	=		$(notdir $(SRCS_PIPEX:.c=.o))
OBJ_TEST		=	$(notdir $(SRCS_TEST:.c=.o))

OBJS_PIPEX		=	$(addprefix $(OBJ_PATH_PIPEX), $(OBJ_PIPEX))
OBJS_TEST		=	$(addprefix $(OBJ_PATH_TEST), $(OBJ_TEST))


#-----------------------------------
#         COMPILATION RULES
#-----------------------------------

# Compiler and compiler flags
CC			=	cc
CFLAGS		=	-Wall -Werror -Wextra -g

# All target : all .c files necessary to build the final binary
all: $(LIBFT) $(NAME)
tests : $(TEST)

# Rule for normal compilation
$(OBJ_PATH_PIPEX)%.o: $(SRC_PATH)%.c | $(OBJ_PATH_PIPEX)
	@$(CC) $(CFLAGS) -c $< -o $@ $(INC)

$(OBJ_PATH_TEST)%.o: $(SRC_PATH)%.c | $(OBJ_PATH_TEST)
	@$(CC) $(CFLAGS) -c $< -o $@ $(INC)

$(OBJ_PATH_TEST)%.o: $(TEST_DIR)/%.c | $(OBJ_PATH_TEST)
	@$(CC) $(CFLAGS) -c $< -o $@ $(INC)

# create object directories
$(OBJ_PATH_PIPEX):
	@mkdir -p $(OBJ_PATH_PIPEX)

$(OBJ_PATH_TEST):
	@mkdir -p $(OBJ_PATH_TEST)

#Compile Libft
$(LIBFT):
	@echo "Making libft..."
	@make -C $(LIBFT_PATH)
#@make -sC $(LIBFT_PATH)

# Build 'pipex'
$(NAME): $(OBJS_PIPEX) $(LIBFT)
	@echo "Compiling pipex..."
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJS_PIPEX) $(LIBFT) $(INC)
	@echo "Pipex is ready."

# Build 'test'
$(TEST): $(OBJS_TEST) $(LIBFT)
	@echo "Compiling test..."
	@$(CC) $(CFLAGS) -o $(TEST) $(OBJS_TEST) $(LIBFT) $(INC)
	@echo "Test is ready."

#-----------------------------------
#           CLEANING RULES
#-----------------------------------

# Clean object files
clean:
	@echo "Removing .o object files ..."
	@rm -rf $(OBJ_PATH_PIPEX)
	@rm -rf $(OBJ_PATH_TEST)
	@make clean -C $(LIBFT_PATH)

# Full clean : removes both .o files and final executable)
fclean: clean
	@echo "Removing executables ..."
	@rm -f $(NAME) $(TEST)
	@rm -f $(LIBFT_PATH)$(LIBFT_NAME)

# Rebuild everything (clean and then build all)
re: fclean all

# Phony targets
.PHONY: all clean fclean re tests