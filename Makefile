NAME = push_swap
NAMEB = cheker

CFLAGS = -Wall -Werror -Wextra 
CC = cc
FT_PRINTF = ./ft_printf/libftprintf.a
# FT_PRINTF = ./ft_printf/libftprintf.a

SRC = push_swap.c utils.c utils2.c utils3.c free.c parsing.c\
	linkedlists.c linkedlists1.c fillstack.c moves.c index.c ft_split.c\
	sort3.c sort_more.c sort5.c 

SRCB = checker.c utils.c utils2.c utils3.c free.c parsing.c\
	linkedlists.c linkedlists1.c fillstack.c moves.c index.c ft_split.c\
	sort3.c sort_more.c sort5.c ft_strcmp.c get_next_line.c\
	get_next_line_utils.c


OBJC =  $(SRC:.c=.o)
OBJCB =  $(SRCB:.c=.o)

all: $(NAME)
bonus : $(NAMEB)

$(OBJC) : $(SRC)
$(OBJCB) : $(SRCB)

$(NAME): $(OBJC) $(FT_PRINTF)
	@-$(CC) $(OBJC) $(FT_PRINTF) -o $(NAME)

$(NAMEB): $(OBJCB) $(FT_PRINTF)
	@-$(CC) $(OBJCB) $(FT_PRINTF) -o $(NAMEB)

$(FT_PRINTF):
	@-make -C ft_printf

%.o: %.c
	@-$(CC) $(CFLAGS) -c $< -o $@

clean:
	@-rm -rf $(OBJC) $(OBJCB)
	@-make clean -C ft_printf

fclean: clean
	@-rm -rf $(NAME) $(NAMEB)
	@-make fclean -C ft_printf

re: fclean 
	@-$(MAKE) all
	@-$(MAKE) bonus
	@-$(MAKE) clean
	

.SECONDARY:  $(OBJC) $(OBJCB)