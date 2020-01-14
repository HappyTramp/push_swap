RM = rm -f

CC = gcc
CCFLAGS = -Wall -Wextra #-Werror

CHECKER_NAME = checker
CHECKER_SRC = checker_src/main.c
CHECKER_OBJ = $(CHECKER_SRC:.c=.o)

PUSH_SWAP_NAME = push_swap
PUSH_SWAP_SRC = push_swap_src/main.c
PUSH_SWAP_OBJ = $(PUSH_SWAP_SRC:.c=.o)


all: $(CHECKER_NAME) $(PUSH_SWAP_NAME)

$(CHECKER_NAME): $(CHECKER_OBJ) $(CHECKER_HEADER)
	$(CC) -o $@ $(CHECKER_OBJ)

$(PUSH_SWAP_NAME): $(PUSH_SWAP_OBJ) $(PUSH_SWAP_HEADER)
	$(CC) -o $@ $(PUSH_SWAP_OBJ)

%.o: %.c
	$(CC) $(CCFLAGS) -c -o $@ $<

clean:
	$(RM) $(CHECKER_OBJ)
	$(RM) $(PUSH_SWAP_OBJ)

fclean: clean
	$(RM) $(CHECKER_NAME)
	$(RM) $(PUSH_SWAP_NAME)

re: fclean all
