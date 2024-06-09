NAME = push_swap
CFLAGS = -Wall -Werror -Wextra 
CC = cc
FT_PRINTF = ./ft_printf/libftprintf.a
SRC = ./get_next_line/get_next_line.c \
	./get_next_line/get_next_line_utils.c  \
	push_swap.c split.c free.c\
	linkedlists.c
OBJC =  $(SRC:.c=.o)

all: $(NAME)

$(OBJC) : $(SRC)

$(NAME): $(OBJC) $(FT_PRINTF)
	@-$(CC) $(OBJC) $(FT_PRINTF) -o $(NAME)

$(FT_PRINTF):
	@-make -C ft_printf

%.o: %.c
	@-$(CC) $(CFLAGS) -c $< -o $@

clean:
	@-rm -rf $(OBJC) 
	@-make clean -C ft_printf

fclean: clean
	@-rm -rf $(NAME)
	@-make fclean -C ft_printf

re: fclean 
	@-$(MAKE) all
	@-$(MAKE) clean
	

.SECONDARY:  $(OBJC) 