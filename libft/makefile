#-----------------------------------
#          NAMES and PATHS          
#-----------------------------------

# Name of final binary (static library)
NAME = libft.a

# Directories
SRC_DIR = source
OBJ_DIR = object
INC_DIR = include

# Sub directories
SUBDIRS = \
	1_char \
	2_string \
	3_memory \
	4_conversion \
	5_output \
	6_printf \
	7_get_next_line

# List of source files
CHAR_SRCS = \
	$(SRC_DIR)/1_char/ft_isalnum.c \
	$(SRC_DIR)/1_char/ft_isalpha.c \
	$(SRC_DIR)/1_char/ft_isascii.c \
	$(SRC_DIR)/1_char/ft_isdigit.c \
	$(SRC_DIR)/1_char/ft_isprint.c \
	$(SRC_DIR)/1_char/ft_toupper.c \
	$(SRC_DIR)/1_char/ft_tolower.c

STRING_SRCS = \
	$(SRC_DIR)/2_string/ft_split.c \
	$(SRC_DIR)/2_string/ft_strchr.c \
	$(SRC_DIR)/2_string/ft_strdup.c \
	$(SRC_DIR)/2_string/ft_striteri.c \
	$(SRC_DIR)/2_string/ft_strjoin.c \
	$(SRC_DIR)/2_string/ft_strlcat.c \
	$(SRC_DIR)/2_string/ft_strlcpy.c \
	$(SRC_DIR)/2_string/ft_strlen.c \
	$(SRC_DIR)/2_string/ft_strmapi.c \
	$(SRC_DIR)/2_string/ft_strncmp.c \
	$(SRC_DIR)/2_string/ft_strnstr.c \
	$(SRC_DIR)/2_string/ft_strrchr.c \
	$(SRC_DIR)/2_string/ft_strtrim.c \
	$(SRC_DIR)/2_string/ft_substr.c

MEMORY_SRCS = \
	$(SRC_DIR)/3_memory/ft_bzero.c \
	$(SRC_DIR)/3_memory/ft_calloc.c \
	$(SRC_DIR)/3_memory/ft_memchr.c \
	$(SRC_DIR)/3_memory/ft_memcmp.c \
	$(SRC_DIR)/3_memory/ft_memcpy.c \
	$(SRC_DIR)/3_memory/ft_memmove.c \
	$(SRC_DIR)/3_memory/ft_memset.c

CONVERSION_SRCS = \
	$(SRC_DIR)/4_conversion/ft_atoi.c \
	$(SRC_DIR)/4_conversion/ft_itoa.c

OUTPUT_SRCS = \
	$(SRC_DIR)/5_output/ft_putchar_fd.c \
	$(SRC_DIR)/5_output/ft_putnbr_fd.c \
	$(SRC_DIR)/5_output/ft_putendl_fd.c \
	$(SRC_DIR)/5_output/ft_putstr_fd.c

PRINTF_SRCS = \
	$(SRC_DIR)/6_printf/check_format.c \
	$(SRC_DIR)/6_printf/ft_printf.c \
	$(SRC_DIR)/6_printf/print_char.c \
	$(SRC_DIR)/6_printf/print_hex.c \
	$(SRC_DIR)/6_printf/print_number.c \
	$(SRC_DIR)/6_printf/print_pointer.c \
	$(SRC_DIR)/6_printf/print_string.c \
	$(SRC_DIR)/6_printf/print_unsigned.c

GNL_SRCS = \
	$(SRC_DIR)/7_get_next_line/get_next_line_utils.c \
	$(SRC_DIR)/7_get_next_line/get_next_line.c

# Concatenate all source files into one variable
SRCS = \
	$(CHAR_SRCS) \
	$(STRING_SRCS) \
	$(MEMORY_SRCS) \
	$(CONVERSION_SRCS) \
	$(OUTPUT_SRCS) \
	$(PRINTF_SRCS) \
	$(GNL_SRCS)

# List of object files
OBJS = $(SRCS:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

#-----------------------------------
#              RULES
#-----------------------------------

# Define compiler and compiler flags
CC = gcc
CFLAGS = -Wall -Werror -Wextra -I$(INC_DIR)

# Rule for all .c files necessary to build the final binary
all: $(NAME)

# To make $(NAME), create all .o files 
$(NAME): $(OBJS)
	@$(AR) -r $(NAME) $?
	@echo "Library 'libft.a' created !"

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(OBJ_DIR)/$(patsubst $(SRC_DIR)/%,%,$(dir $<))
	@$(CC) $(CFLAGS) -c $< -o $@

# Create 'object' directory if it doesn't exist
$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

## // CLEANING RULES

# Remove $(OBJ) => (.o) files
clean:
	@rm -rf $(OBJ_DIR)
	@echo "Object files cleaned !"

# Remove $(NAME) => final binary
fclean: clean
	@rm -f $(NAME)
	@echo "Library 'libft.a' removed !"

# Remove all and compile: remove $(OBJ) and $(NAME) and compile all
re: fclean all

# Phony targets
.PHONY: all clean fclean re
