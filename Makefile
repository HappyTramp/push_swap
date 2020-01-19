RM = rm -f

LIBFT_DIR = libft

CC = gcc
CCFLAGS = -I$(COMMON_DIR) -I$(LIBFT_DIR)/include -Wall -Wextra -g#-Werror
LDFLAGS = -L$(LIBFT_DIR) -lft

SRC_DIR = src

COMMON_DIR = $(SRC_DIR)/common
CHECKER_NAME = checker

COMMON_HEADER = $(COMMON_DIR)/common.h
COMMON_FILES = stack_core.c stack_op.c stack_helper.c parse.c
COMMON_SRC = $(addprefix $(COMMON_DIR)/,$(COMMON_FILES))
COMMON_OBJ = $(COMMON_SRC:.c=.o)

PUSH_SWAP_NAME = push_swap
CHECKER_DIR = $(SRC_DIR)/checker
PUSH_SWAP_DIR = $(SRC_DIR)/push_swap

CHECKER_HEADER = $(CHECKER_DIR)/checker.h
CHECKER_FILES = main.c check.c
CHECKER_SRC = $(addprefix $(CHECKER_DIR)/,$(CHECKER_FILES))
CHECKER_OBJ = $(CHECKER_SRC:.c=.o)
CHECKER_OBJ += $(COMMON_OBJ)

PUSH_SWAP_HEADER = $(PUSH_SWAP_DIR)/push_swap.h
PUSH_SWAP_FILES = main.c sort.c stack_wrapper.c
PUSH_SWAP_SRC = $(addprefix $(PUSH_SWAP_DIR)/,$(PUSH_SWAP_FILES))
PUSH_SWAP_OBJ = $(PUSH_SWAP_SRC:.c=.o)
PUSH_SWAP_OBJ += $(COMMON_OBJ)

all: libft_all $(CHECKER_NAME) $(PUSH_SWAP_NAME)

$(CHECKER_NAME): CCFLAGS += -I$(CHECKER_DIR)
$(CHECKER_NAME): $(CHECKER_OBJ) $(CHECKER_HEADER) $(LIBFT_DIR)/libft.a
	$(CC) $(LDFLAGS) -o $@ $(CHECKER_OBJ)

$(PUSH_SWAP_NAME): CCFLAGS += -I$(PUSH_SWAP_DIR)
$(PUSH_SWAP_NAME): $(PUSH_SWAP_OBJ) $(PUSH_SWAP_HEADER) $(LIBFT_DIR)/libft.a
	$(CC) $(LDFLAGS) -o $@ $(PUSH_SWAP_OBJ)

%.o: %.c
	$(CC) $(CCFLAGS) -c -o $@ $<

clean:
	$(RM) $(CHECKER_OBJ)
	$(RM) $(PUSH_SWAP_OBJ)
	make -C $(LIBFT_DIR) fclean

fclean:
	$(RM) $(CHECKER_OBJ) $(CHECKER_NAME)
	$(RM) $(PUSH_SWAP_OBJ) $(PUSH_SWAP_NAME)
	make -C $(LIBFT_DIR) fclean

re:
	make fclean
	make all

libft_all:
	make -C $(LIBFT_DIR)
